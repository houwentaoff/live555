/*
****************************************************************************
*
** \file      rtsp_server.cpp
**
** \version   
**
** \brief     rtsp server
**
** \attention THIS SAMPLE CODE IS PROVIDED AS IS. GOFORTUNE SEMICONDUCTOR
**            ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR 
**            OMMISSIONS.
**
** (C) Copyright 2012-2013 by GOKE MICROELECTRONICS CO.,LTD
**
****************************************************************************
*/

#include <stdio.h>
#include <getopt.h>
#include <sched.h>
#include <pthread.h>
#include <signal.h>
#include "liveMedia.hh"
#include "BasicUsageEnvironment.hh"
#include "GroupsockHelper.hh"
//#include "MyH264VideoStreamFramer.hh"
//#include "MyH264VideoRTPSink.hh"
#include "H264VideoFileServerMediaSubsession.hh"
//#include "MyJPEGVideoSource.hh"
//#include "MyJPEGVideoRTPSink.hh"

#include <fcntl.h>
#include <sys/ioctl.h>
#include <basetypes.h>
#include "iav_drv.h"
#include "iav_drv_ex.h"
#include "bsreader.h"
#include "config.h"


#ifdef CONFIG_ARCH_GK1107
#define	MAX_ENCODE_STREAM_NUM	(2)
#else
#ifdef CONFIG_ARCH_A7
#define	MAX_ENCODE_STREAM_NUM	(2)
#else
#ifdef CONFIG_ARCH_S2
#define	MAX_ENCODE_STREAM_NUM	(2)
#endif
#endif
#endif

#define	MAX_ENCODE_STREAM_NUM	(4)

UsageEnvironment* env;

char const* descriptionString = "Session streamed by \"GOKE RTSP Server\"";


static portNumBits clientPort;
static Boolean is_ssm = False;

static char inputFileName[256]= "";
static char inputFileName2[256]= "";

/* To make the second and subsequent client for each stream reuse the same
 * input stream as the first client (rather than playing the file from the
 * start for each client), change the following "False" to "True":
 */
Boolean reuseFirstSource = True;

// options and usage
#define NO_ARG		0
#define HAS_ARG		1
static struct option long_options[] = {
	{0, 0, 0, 0}	
};

static const char *short_options = "c:sf:g:";

int init_param(int argc, char **argv)
{
	int ch;
	int option_index = 0;

	opterr = 0;
	while ((ch = getopt_long(argc, argv, short_options, long_options, &option_index)) != -1) {
		switch (ch) {
		case 'c':
			clientPort = atoi(optarg);
			break;
		case 's':
			is_ssm = True;
			break;
		case 'f':
			strcpy(inputFileName, optarg);
			break;
		case 'g':
			strcpy(inputFileName2, optarg);
			break;
		default:
			printf("unknown command %s \n", optarg);
			return -1;
			break;
		}
	}

	return 0;
}

int map_bsb(int fd_iav)
{
	iav_mmap_info_t info;
	static int mem_mapped = 0;

	if (mem_mapped)
		return 0;

	if (ioctl(fd_iav, IAV_IOC_MAP_BSB2, &info) < 0) {
		perror("IAV_IOC_MAP_BSB");
		return -1;
	}

	if (ioctl(fd_iav, IAV_IOC_MAP_DSP, &info) < 0) {
		perror("IAV_IOC_MAP_DSP");
		return -1;
	}

	mem_mapped = 1;
	return 0;
}

int bsreader()
{
	int fd_iav;
	bsreader_init_data_t  init_data;

	if ((fd_iav = open("/dev/iav", O_RDWR, 0)) < 0) {
		perror("/dev/iav");
		return -1;
	}
	if (map_bsb(fd_iav) < 0) {
		printf("map bsb failed\n");
		return -1;
	}

	memset(&init_data, 0, sizeof(init_data));
	init_data.fd_iav = fd_iav;
	init_data.max_stream_num = MAX_ENCODE_STREAM_NUM;
	init_data.ring_buf_size[0] = 1024*1024*4;  // 8MB
	init_data.ring_buf_size[1] = 1024*1024*2;  // 2MB
 /* :TODO:2014/9/16 13:51:38:Sean:  2*/
#if 1
	init_data.ring_buf_size[2] = 1024*1024*1;  // 1MB
	init_data.ring_buf_size[3] = 1024*1024*1;  // 1MB
#endif
 /* :TODO:End---  */
	/* Enable cavlc encoding when configured.
	 * This option will use more memory in bsreader on A5s arch.
	 */
	init_data.cavlc_possible = 1;

	if (bsreader_init(&init_data) < 0) {
		printf("bsreader init failed \n");
		return -1;
	}

	if (bsreader_open() < 0) {
		printf("bsreader open failed \n");
		return -1;
	}
	return 0;
}

void create_live_stream(RTSPServer * rtspServer, int stream,
	UsageEnvironment * env_stream)
{
	char streamName[32], inputFileName[32];
	sprintf(streamName, "stream%d", (stream+1));
	sprintf(inputFileName, "live_stream%d", (stream+1));

	ServerMediaSession * sms =
		ServerMediaSession::createNew(*env, streamName, streamName,
			descriptionString, is_ssm /*SSM*/);
	ServerMediaSubsession * subsession =
		H264VideoFileServerMediaSubsession::createNew(*env_stream,
			inputFileName, reuseFirstSource);

	sms->addSubsession(subsession);
	subsession->setServerAddressAndPortForSDP(0, clientPort);
	rtspServer->addServerMediaSession(sms);

	char *url = rtspServer->rtspURL(sms);
	*env << "Play this stream using the URL \"" << url << "\"\n";
	delete[] url;
}

void setup_streams(RTSPServer * rtspServer)
{
	TaskScheduler * scheduler[MAX_ENCODE_STREAM_NUM];
	UsageEnvironment * env_stream[MAX_ENCODE_STREAM_NUM];
	int i;

	for (i = 0; i < MAX_ENCODE_STREAM_NUM; ++i) {
		scheduler[i] = BasicTaskScheduler::createNew();
		env_stream[i] = BasicUsageEnvironment::createNew(*scheduler[i]);
		create_live_stream(rtspServer, i, env_stream[i]);
	}
}

static void sighandler(int sig_no)
{
	if (bsreader_close() < 0) {
		printf("bsreader_close() failed!\n");
	}
	exit(0);
}

int main(int argc, char** argv) 
{
	signal(SIGINT, sighandler);
	signal(SIGQUIT, sighandler);
	signal(SIGTERM, sighandler);

	if (init_param(argc, argv) < 0) {
		printf("init param failed \n");
		return -1;
	}

	// Begin by setting up our usage environment:
	TaskScheduler* scheduler = BasicTaskScheduler::createNew();
	env = BasicUsageEnvironment::createNew(*scheduler);

	UserAuthenticationDatabase* authDB = NULL;
#ifdef ACCESS_CONTROL
	// To implement client access control to the RTSP server, do the following:
	authDB = new UserAuthenticationDatabase;
	authDB->addUserRecord("username1", "password1"); // replace these with real strings
	// Repeat the above with each <username>, <password> that you wish to allow
	// access to the server.
#endif
/* :TODO:2014/9/15 16:18:27:Sean:  default is 300000  */
      OutPacketBuffer::maxSize = 2000000;
/* :TODO:End---  */
	// Create the RTSP server:
	RTSPServer* rtspServer = RTSPServer::createNew(*env, 554, authDB);
	if (rtspServer == NULL) {
		*env << "Failed to create RTSP server: " << env->getResultMsg() << "\n";
		exit(1);
	}
	if (0!=bsreader())
    {
		exit(-2);
    }

	setup_streams(rtspServer);

	 // does not return
	env->taskScheduler().doEventLoop();

	return 0;
}

