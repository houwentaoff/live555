/*
****************************************************************************
*
** \file      ./server/rtsp_server.cpp
**
** \version   $Id:
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
#include "MyH264VideoStreamFramer.hh"
#include "MyH264VideoRTPSink.hh"
#include "H264VideoFileServerMediaSubsession.hh"
#include "MyJPEGVideoSource.hh"
#include "MyJPEGVideoRTPSink.hh"

#include <fcntl.h>
#include <sys/ioctl.h>
#include <basetypes.h>
#include "iav_drv.h"
#include "iav_drv_ex.h"
#include "bsreader.h"
//#include "config.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>

#ifdef CONFIG_ARCH_GK7101
#define	MAX_ENCODE_STREAM_NUM	(2)
#else
#define	MAX_ENCODE_STREAM_NUM	(4)
#endif

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
/* Last element is marked by mult == 0 */
struct suffix_mult {
	char suffix[4];
	unsigned mult;
};
static const struct suffix_mult rtsp_server_sfx[] = {
	{ "c", 1 },
	{ "w", 2 },
	{ "b", 512 },
	{ "kD", 1000 },
	{ "k", 1024 },
	{ "K", 1024 },  
	{ "MD", 1000000 },
	{ "M", 1048576 },
	{ "GD", 1000000000 },
	{ "G", 1073741824 },
	{ "", 0 }
};

static struct {
   unsigned long num;
   unsigned long size[6];
} Z;

static void bb_show_usage(const char *applet_name)
{
	fprintf(stderr, "Usage: %s [num=stream_num[1 ... 4]] [size=size1,size2,size3,size4 c/w/b/kD/k/K/MD/M/GD/G]....\n c=1 byte, w=2 b=512 kD=1000 k/K=1024 MD=1000000 M=1024*1024 GD=1000*1000*1000 G=1024*1024*1024 bytes. \neg:.%s num=4 size=4M,2M,1M,1M\n",
		applet_name, applet_name);
	exit(-1);
}
static int  index_in_strings(const char *strings, const char *key)
{
	int idx = 0;

	while (*strings) {
		if (strcmp(strings, key) == 0) {
			return idx;
		}
		strings += strlen(strings) + 1; /* skip NUL */
		idx++;
	}
	return (-1);
}
static unsigned long xatoul_range_sfx(const char *numstr, unsigned long lower,  unsigned long upper, const struct suffix_mult *suffixes)
{
	unsigned long r;
	char *e;
    
    	/* Disallow '-' and any leading whitespace. */
	if (*numstr == '-' || *numstr == '+' || isspace(*numstr))
		goto inval;

	r = strtoul(numstr, &e, 10);
	if (numstr == e)
		goto inval;
    /* error / no digits / illegal trailing chars */
    /* Do optional suffix parsing.  Allow 'empty' suffix tables.
	 * Note that we also allow nul suffixes with associated multipliers,
	 * to allow for scaling of the numstr by some default multiplier. */
	if (suffixes) {
		while (suffixes->mult) {
			if (strcmp(suffixes->suffix, e) == 0) {
				if (ULONG_MAX / suffixes->mult < r)
					goto range; /* overflow! */
				r *= suffixes->mult;
				goto chk_range;
			}
			++suffixes;
		}
	}

	/* Note: trailing space is an error.
	 * It would be easy enough to allow though if desired. */
	if (*e)
		goto inval;
 chk_range:
	/* Finally, check for range limits. */
	if (r >= lower && r <= upper)
		return r;
 range:
	fprintf(stderr, "number %s is not in %llu..%llu range\n",
		numstr, (unsigned long long)lower,
		(unsigned long long)upper);
	exit(-2);
 inval:
	fprintf(stderr, "invalid number '%s'\n", numstr);    
	exit(-3);
}

static int parse_param ( int argc, char *argv[] )
{
    static const char keywords[] =
        "num\0""size\0"
        ;
    enum {
        OP_num = 0,
        OP_size,
    };

    ssize_t n;
    unsigned long * psize=Z.size;

    if (1 == argc)
    {
        Z.num = MAX_ENCODE_STREAM_NUM;
        Z.size[0] = 4*1024*1024;/*4M*/
        Z.size[1] = 1*1024*1024;/*1M*/
        Z.size[2] = 1*1024*1024;/*1M*/
        Z.size[3] = 1*1024*1024;/*1M*/
        return (0);
    }
	memset(&Z, 0, sizeof(Z));
    psize = Z.size;

	for (n = 1; argv[n]; n++) {
		int what;
		char *val;
		char *arg = argv[n];    
        
		val = strchr(arg, '=');
		if (val == NULL)
			bb_show_usage(argv[0]);
		*val = '\0';
		what = index_in_strings(keywords, arg);
		if (what < 0)
			bb_show_usage(argv[0]);
		/* *val = '='; - to preserve ps listing? */
		val++;

		if (what == OP_num) {
            Z.num = atol(val);
            if (Z.num > 4){
                bb_show_usage(argv[0]);
            }
			/*continue;*/
		}
        if (what == OP_size) {
			while (1) {
				/* find ',', replace them with NUL so we can use val for
				 * index_in_strings() without copying.
				 * We rely on val being non-null, else strchr would fault.
				 */
				arg = strchr(val, ',');
				if (arg)
					*arg = '\0';
                *(psize++) = xatoul_range_sfx(val, 1, ((size_t)-1L)/2, rtsp_server_sfx);
                
				if (!arg) /* no ',' left, so this was the last specifier */
					break;
				/* *arg = ','; - to preserve ps listing? */
				val = arg + 1; /* skip this keyword and ',' */
			}
			continue; /* we trashed 'what', can't fall through */
		}
    }

    //printf("Z.num[%lu],size[%lu][%ld][%lu][%lu]\n", Z.num, Z.size[0], Z.size[1], Z.size[2], Z.size[3]);
    return 0;
}				

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
    int i=0;
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
	for (i=0;i<Z.num;i++)
    {
        init_data.ring_buf_size[i] = Z.size[i];
    }
    init_data.max_stream_num = Z.num;
    
	/* Enable cavlc encoding when configured.
	 * This option will use more memory in bsreader on A5s arch.
	 */
	init_data.cavlc_possible = 0;
    printf("Z.num[%lu]init_data.max_stream_num[%d],size[%d][%d][%d][%d]\n",
        Z.num,
        init_data.max_stream_num, init_data.ring_buf_size[0],
        init_data.ring_buf_size[1],init_data.ring_buf_size[2],
        init_data.ring_buf_size[3]);

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
	TaskScheduler * scheduler[Z.num];
	UsageEnvironment * env_stream[Z.num];
	int i;

	for (i = 0; i < Z.num; ++i) {
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

#if 0
	if (init_param(argc, argv) < 0) {
		printf("init param failed \n");
		return -1;
	}
#else
    parse_param(argc, argv);
#endif

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
/* :TODO:2014/9/15 16:18:27:Sean:  default is 300000 导致挂掉的元凶*/
      OutPacketBuffer::maxSize = 2000000;
/* :TODO:End---  */
	// Create the RTSP server:
	RTSPServer* rtspServer = RTSPServer::createNew(*env, 554, authDB);
	if (rtspServer == NULL) {
		*env << "Failed to create RTSP server: " << env->getResultMsg() << "\n";
		exit(1);
	}
	bsreader();

	setup_streams(rtspServer);

	 // does not return
	env->taskScheduler().doEventLoop();

	return 0;
}

