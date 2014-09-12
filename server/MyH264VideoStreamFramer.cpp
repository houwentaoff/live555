#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <basetypes.h>
#include "iav_drv.h"
#include "iav_drv_ex.h"
#include "MyH264VideoStreamFramer.hh"
#include "H264StreamParser.hh"
#include "assert.h"

MyH264VideoStreamFramer*
MyH264VideoStreamFramer::createNew(UsageEnvironment & env, FramedSource * inputSource)
{
	return new MyH264VideoStreamFramer(env,inputSource);
}

MyH264VideoStreamFramer*
MyH264VideoStreamFramer::createNew(UsageEnvironment & env, int streamID)
{
	return new MyH264VideoStreamFramer(env, streamID);
}

MyH264VideoStreamFramer::MyH264VideoStreamFramer(UsageEnvironment & env, FramedSource * inputSource)
: H264VideoStreamFramer(env,inputSource, NULL, NULL),fFrameRate(30),fPictureEndMarker(False)
{
	assert(inputSource);
	fParser = new H264FileStreamParser(this, inputSource);
	fBitstreamParser = NULL;
	fStreamID = -1;
}

MyH264VideoStreamFramer::MyH264VideoStreamFramer(UsageEnvironment & env, int streamID)
: H264VideoStreamFramer(env, NULL, NULL, NULL),fFrameRate(30),fPictureEndMarker(False)
{
	assert(streamID >= 0 && streamID < 4);
	fBitstreamParser = new H264BitStreamParser(streamID);
	fParser = NULL;
	fStreamID = streamID;
	fFrameNum = 0;
}

MyH264VideoStreamFramer::~MyH264VideoStreamFramer()
{
	printf("~MyH264VideoStreamFramer\n");
	if (fBitstreamParser)
		delete fBitstreamParser;
	if (fParser)
		delete fParser;
}

void MyH264VideoStreamFramer::doGetNextFrame()
{
//	printf("				  StreamFramer::doGetNextFrame\n");		//jay
	if (fBitstreamParser != NULL)
		fBitstreamParser->registerReadInterest(fTo, fMaxSize);
	if (fParser != NULL)
		fParser->registerReadInterest(fTo, fMaxSize);
	continueReadProcessing();
//	printf("				  StreamFramer::doGetNextFrame - end\n");	//jay
}

Boolean MyH264VideoStreamFramer::isH264VideoStreamFramer() const
{
	return True;
}

Boolean MyH264VideoStreamFramer::pictureEndMarker()
{
	return fPictureEndMarker;
}

Boolean MyH264VideoStreamFramer::currentNALUnitEndsAccessUnit()
{
 	return True;
}

char* MyH264VideoStreamFramer:: getSPS()
{
	if (fParser != NULL)
		return fParser->getParsersps();
	else
		return fBitstreamParser->getParsersps();
}

char* MyH264VideoStreamFramer::getPPS()
{
	if (fParser != NULL)
		return fParser->getParserpps();
	else
		return fBitstreamParser->getParserpps();
}

char* MyH264VideoStreamFramer::getProfileLevelID()
{
	if (fParser != NULL)
		//return fParser->getPreID();
		return NULL;
	else
		return fBitstreamParser->getPreID();
}

int MyH264VideoStreamFramer::getStreamID()
{
	return fStreamID;
}

void MyH264VideoStreamFramer::continueReadProcessing(void* clientData,
	unsigned char* /*ptr*/,unsigned/* size*/,struct timeval /*presentationTime*/)
{
	MyH264VideoStreamFramer* framer = (MyH264VideoStreamFramer*) clientData;
	framer->continueReadProcessing();
}

void MyH264VideoStreamFramer::continueReadProcessing()
{
	unsigned acquiredFrameSize;
	u_int64_t frameDuration_usec;

	if (fBitstreamParser != NULL && fParser == NULL) {

		if (fBitstreamParser->parse() < 0)
			return;

		//printf("nalu_type %d, size %d\n", fBitstreamParser->fNaluType, fBitstreamParser->fNaluSize);		//jay
		acquiredFrameSize = fBitstreamParser->fNaluSize;
		if (acquiredFrameSize > 0)
		{
			fFrameSize = acquiredFrameSize;
			if (!fBitstreamParser->fIsNewSession) {
				if (fBitstreamParser->fPTS < fPTS) {
					frameDuration_usec = ((1<<30) + fBitstreamParser->fPTS - fPTS) * 100 / 9;		//yzhu
				} else {
					frameDuration_usec = (fBitstreamParser->fPTS - fPTS) * 100 / 9;	//pts is creatmented @ 90000Hz
				}
			}
			else
				frameDuration_usec = 0;

			fPTS = fBitstreamParser->fPTS;

		//	if (fBitstreamParser->fNaluType == 7) {		//SPS NALU
		//		gettimeofday(&fPresentationTime, NULL);		//disable PTS auto adjustment
		//	}
		//	if (fBitstreamParser->fNaluType == NALU_TYPE_AUD)	{	//IP NALU
		//		fPresentationTime.tv_usec += (long) frameDuration_usec;
		//	}
			// use frame num update to update RTP packet pts
			if ((fFrameNum == 0) || (fFrameNum != fBitstreamParser->getFrameNum())) {
				fPresentationTime.tv_usec += (long) frameDuration_usec;
				fFrameNum = fBitstreamParser->getFrameNum();
			}

			while (fPresentationTime.tv_usec >= 1000000)
			{
				fPresentationTime.tv_usec -= 1000000;
				++fPresentationTime.tv_sec;
			}

			fDurationInMicroseconds = 0;		//schedule as quick as possible after get one NALU
#if 0	//jay
	static struct timeval prev_pts;
	printf("\npt: %d sec %d usec, diff %d\n", fPresentationTime.tv_sec, fPresentationTime.tv_usec,
		(fPresentationTime.tv_sec - prev_pts.tv_sec)*1000000 + fPresentationTime.tv_usec - prev_pts.tv_usec);
	prev_pts = fPresentationTime;
#endif
			afterGetting(this);
		}
	}
	else
	{
		frameDuration_usec = 1000000 / fFrameRate;
		acquiredFrameSize = fParser->parse();
	//	printf("nalu_type %d\n", fParser->fNaluType);		//jay
		if (acquiredFrameSize > 0)
		{
			fFrameSize = acquiredFrameSize;

			if (fParser->fNaluType == NALU_TYPE_SPS) {		//SPS NALU
				gettimeofday(&fPresentationTime, NULL);
			}
			// use frame num update to update RTP packet pts
			if ((fFrameNum == 0) || (fFrameNum != fBitstreamParser->getFrameNum())) {
				fPresentationTime.tv_usec += (long) frameDuration_usec;
				fDurationInMicroseconds = (unsigned int )frameDuration_usec;
				fFrameNum = fBitstreamParser->getFrameNum();
			}

			while (fPresentationTime.tv_usec >= 1000000)
			{
				fPresentationTime.tv_usec -= 1000000;
				++fPresentationTime.tv_sec;
			}
	//		if (fParser->fNaluType == 7 || fParser->fNaluType == 1)

			afterGetting(this);
		}
	}
//	printf("					  StreamFramer: afterGetting\n");		//jay
}


//++++
