#/*
#****************************************************************************
#*
#** \file      Makefile
#**
#** \version   
#**
#** \brief     
#**
#** \attention THIS SAMPLE CODE IS PROVIDED AS IS. GOFORTUNE SEMICONDUCTOR
#**            ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR 
#**            OMMISSIONS.
#**
#** (C) Copyright 2012-2013 by GOKE MICROELECTRONICS CO.,LTD
#**
#****************************************************************************
#*/

default: all

MODULE_NAME		:= RTSP_server

INCLUDES        := -I../UsageEnvironment/include -I../groupsock/include \
				   -I../liveMedia/include -I../BasicUsageEnvironment/include

include ../lib.rules

all:rtsp_server

STREAMER_UNICAST_OBJS = rtsp_server.o \
		H264VideoFileServerMediaSubsession.o \
		MyH264VideoStreamFramer.o \
		MyH264VideoRTPSink.o \
		H264StreamParser.o \
		MyJPEGVideoSource.o \
		MyJPEGVideoRTPSink.o

LOCAL_LIBS = ../liveMedia/libliveMedia.a ../groupsock/libgroupsock.a \
			 ../BasicUsageEnvironment/libBasicUsageEnvironment.a \
			 ../UsageEnvironment/libUsageEnvironment.a
GK_LIBS   += ../bsreader/libbsreader.a

#ifeq ($(CONFIG_ARCH_A5S),y)
#AMBA_LIBS += $(AMBABUILD_TOPDIR)/prebuild/cavlc/libcavlc.a
#endif

LINK_EXTRA_LIBS = -lpthread
LIBS =	$(LOCAL_LIBS) $(GK_LIBS) 
LD   = $(SYS_LIBS) $(LINK_EXTRA_LIBS)

#testH264VideoStreamer$(EXE):	$(STREAMER_OBJS) $(LIBS)
#	@$(CXX) $^ -o $@ $(LD)
	
rtsp_server:$(STREAMER_UNICAST_OBJS) $(LIBS)
	@$(CXX) $^ -o $@ $(LD)

clean:
	@$(ECHO) '  [Clean $(MODULE_NAME)]:'
	@$(RM) *.o rtsp_server 


#STREAMER_APPS = testH264VideoStreamer$(EXE) rtsp_server$(EXE)

MODULE_TARGETS = rtsp_server
