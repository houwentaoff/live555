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

AMBABUILD_TOPDIR  = $(word 1, $(subst /app/ipcam, ,$(shell pwd)))
MODULE_NAME		:= RTSP_server

export AMBABUILD_TOPDIR

INCLUDES = -I../UsageEnvironment/include -I../groupsock/include \
		-I../liveMedia/include -I../BasicUsageEnvironment/include

-include $(AMBABUILD_TOPDIR)/.config
-include $(AMBABUILD_TOPDIR)/build/app/common.mk
-include $(AMBABUILD_TOPDIR)/app/ipcam/live_555/config.mk

RTSP_PATH		= $(APP_PATH)

#STREAMER_OBJS = testH264VideoStreamer.$(OBJ) \
		MyH264VideoStreamFramer.$(OBJ) \
		MyH264VideoRTPSink.$(OBJ) \
		H264StreamParser.$(OBJ) \
		MyJPEGVideoSource.$(OBJ) \
		MyJPEGVideoRTPSink.$(OBJ)

STREAMER_UNICAST_OBJS = rtsp_server.$(OBJ) \
		H264VideoFileServerMediaSubsession.$(OBJ) \
		MyH264VideoStreamFramer.$(OBJ) \
		MyH264VideoRTPSink.$(OBJ) \
		H264StreamParser.$(OBJ) \
		MyJPEGVideoSource.$(OBJ) \
		MyJPEGVideoRTPSink.$(OBJ)

##################### End of local dependences:


##################### Included LIBS:
USAGE_ENVIRONMENT_DIR = ../UsageEnvironment
USAGE_ENVIRONMENT_LIB = $(USAGE_ENVIRONMENT_DIR)/libUsageEnvironment.$(LIB_SUFFIX)
BASIC_USAGE_ENVIRONMENT_DIR = ../BasicUsageEnvironment
BASIC_USAGE_ENVIRONMENT_LIB = $(BASIC_USAGE_ENVIRONMENT_DIR)/libBasicUsageEnvironment.$(LIB_SUFFIX)
LIVEMEDIA_DIR = ../liveMedia
LIVEMEDIA_LIB = $(LIVEMEDIA_DIR)/libliveMedia.$(LIB_SUFFIX)
GROUPSOCK_DIR = ../groupsock
GROUPSOCK_LIB = $(GROUPSOCK_DIR)/libgroupsock.$(LIB_SUFFIX)
LOCAL_LIBS = $(LIVEMEDIA_LIB) $(GROUPSOCK_LIB) \
			$(BASIC_USAGE_ENVIRONMENT_LIB) \
			$(USAGE_ENVIRONMENT_LIB)
AMBA_LIBS = $(AMBABUILD_TOPDIR)/prebuild/bsreader/libbsreader.a
ifeq ($(CONFIG_ARCH_A5S),y)
AMBA_LIBS += $(AMBABUILD_TOPDIR)/prebuild/cavlc/libcavlc.a
endif
LINK_EXTRA_LIBS = -lpthread
LIBS =	$(LOCAL_LIBS) $(AMBA_LIBS) $(LINK_EXTRA_LIBS)
##################### End of Included LIBS:
		

##################### Executable apps:
#testH264VideoStreamer$(EXE):	$(STREAMER_OBJS) $(LIBS)
#	$(LINK)$(EXE_DIR)/$@ $(CONSOLE_LINK_OPTS) $(STREAMER_OBJS) $(LIBS)
	
rtsp_server$(EXE):	$(STREAMER_UNICAST_OBJS) $(LIBS)
	@$(LINK)$(EXE_DIR)/$@ $(CONSOLE_LINK_OPTS) $(STREAMER_UNICAST_OBJS) $(LIBS)
	$(MKDIR) $(RTSP_PATH)
	$(AMBA_MAKEFILE_V)cp -a rtsp_server $(RTSP_PATH)
	$(AMBA_MAKEFILE_V)chmod +x $(RTSP_PATH)/rtsp_server
##################### End of executable apps:


#STREAMER_APPS = testH264VideoStreamer$(EXE) rtsp_server$(EXE)
STREAMER_APPS = rtsp_server$(EXE)

ALL_APPS = $(STREAMER_APPS)

MODULE_TARGETS = $(ALL_APPS)

EXE_DIR	=	.
$(EXE_DIR):
	@$(MKDIR) $(EXE_DIR)

#### Please don't change the following content order in this file
-include $(AMBABUILD_TOPDIR)/app/ipcam/live_555/rules.mk

##### Any additional, platform-specific rules come here:


