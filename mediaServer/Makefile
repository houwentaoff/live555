default: all

AMBABUILD_TOPDIR  = $(word 1, $(subst /app/ipcam, ,$(shell pwd)))
MODULE_NAME		:= mediaServer

export AMBABUILD_TOPDIR

#INCLUDES = -I../UsageEnvironment/include -I../groupsock/include \
		-I../liveMedia/include -I../BasicUsageEnvironment/include

-include $(AMBABUILD_TOPDIR)/app/ipcam/live_555/config.mk


##################### Local dependences:
#live555MediaServer,$(CPP):	DynamicRTSPServer.hh version.hh
#DynamicRTSPServer.$(CPP):	DynamicRTSPServer.hh

#MEDIA_SERVER_OBJS = live555MediaServer.$(OBJ) \
		DynamicRTSPServer.$(OBJ)
##################### End of local dependences:


##################### Included LIBS:
#USAGE_ENVIRONMENT_DIR = ../UsageEnvironment
#USAGE_ENVIRONMENT_LIB = $(USAGE_ENVIRONMENT_DIR)/libUsageEnvironment.$(LIB_SUFFIX)
#BASIC_USAGE_ENVIRONMENT_DIR = ../BasicUsageEnvironment
#BASIC_USAGE_ENVIRONMENT_LIB = $(BASIC_USAGE_ENVIRONMENT_DIR)/libBasicUsageEnvironment.$(LIB_SUFFIX)
#LIVEMEDIA_DIR = ../liveMedia
#LIVEMEDIA_LIB = $(LIVEMEDIA_DIR)/libliveMedia.$(LIB_SUFFIX)
#GROUPSOCK_DIR = ../groupsock
#GROUPSOCK_LIB = $(GROUPSOCK_DIR)/libgroupsock.$(LIB_SUFFIX)
#LOCAL_LIBS = $(LIVEMEDIA_LIB) $(GROUPSOCK_LIB) \
			$(BASIC_USAGE_ENVIRONMENT_LIB) \
			$(USAGE_ENVIRONMENT_LIB)
#LIBS =	$(LOCAL_LIBS) $(LIBS_FOR_CONSOLE_APPLICATION)
##################### End of Included LIBS:


##################### Executable apps:
#live555MediaServer$(EXE):	$(MEDIA_SERVER_OBJS) $(LOCAL_LIBS)
#	@$(LINK)$(EXE_DIR)/$@ $(CONSOLE_LINK_OPTS) $(MEDIA_SERVER_OBJS) $(LIBS)
##################### End of executable apps:


#MEDIA_SERVER = live555MediaServer$(EXE)
























INCLUDES = -I../UsageEnvironment/include -I../groupsock/include -I../liveMedia/include -I../BasicUsageEnvironment/include
# Default library filename suffixes for each library that we link with.  The "config.*" file might redefine these later.
libliveMedia_LIB_SUFFIX = $(LIB_SUFFIX)
libBasicUsageEnvironment_LIB_SUFFIX = $(LIB_SUFFIX)
libUsageEnvironment_LIB_SUFFIX = $(LIB_SUFFIX)
libgroupsock_LIB_SUFFIX = $(LIB_SUFFIX)
##### Change the following for your environment:
COMPILE_OPTS =		$(INCLUDES) -I. -O2 -DSOCKLEN_T=socklen_t -D_LARGEFILE_SOURCE=1 -D_FILE_OFFSET_BITS=64
########Sean
C =			c
C_COMPILER =		cc
C_FLAGS =		$(COMPILE_OPTS) $(CPPFLAGS) $(CFLAGS)
CPP =			cpp
CPLUSPLUS_COMPILER =	c++
CPLUSPLUS_FLAGS =	$(COMPILE_OPTS) -Wall -DBSD=1 $(CPPFLAGS) $(CXXFLAGS)
OBJ =			o
LINK =			c++ -o
LINK_OPTS =		-L. $(LDFLAGS)
CONSOLE_LINK_OPTS =	$(LINK_OPTS)
LIBRARY_LINK =		ar cr 
LIBRARY_LINK_OPTS =	
LIB_SUFFIX =			a
LIBS_FOR_CONSOLE_APPLICATION =
LIBS_FOR_GUI_APPLICATION =
EXE =
##### End of variables to change

MEDIA_SERVER = live555MediaServer$(EXE)
#######Sean
rtspMEDIA_SERVER = rtsp_test1$(EXE)

PREFIX = /usr/local
ALL = $(MEDIA_SERVER) $(rtspMEDIA_SERVER)
all: $(ALL)

.$(C).$(OBJ):
	$(C_COMPILER) -c $(C_FLAGS) $<
.$(CPP).$(OBJ):
	$(CPLUSPLUS_COMPILER) -c $(CPLUSPLUS_FLAGS) $<

MEDIA_SERVER_OBJS = live555MediaServer.$(OBJ) DynamicRTSPServer.$(OBJ)
########Sean
rtspMEDIA_SERVER_OBJS = rtsp_test1.$(OBJ) #DynamicRTSPServer.$(OBJ)

live555MediaServer.$(CPP):	DynamicRTSPServer.hh version.hh
DynamicRTSPServer.$(CPP):	DynamicRTSPServer.hh
########Sean	
#rtsp_test1.$(CPP):	DynamicRTSPServer.hh

USAGE_ENVIRONMENT_DIR = ../UsageEnvironment
USAGE_ENVIRONMENT_LIB = $(USAGE_ENVIRONMENT_DIR)/libUsageEnvironment.$(libUsageEnvironment_LIB_SUFFIX)
BASIC_USAGE_ENVIRONMENT_DIR = ../BasicUsageEnvironment
BASIC_USAGE_ENVIRONMENT_LIB = $(BASIC_USAGE_ENVIRONMENT_DIR)/libBasicUsageEnvironment.$(libBasicUsageEnvironment_LIB_SUFFIX)
LIVEMEDIA_DIR = ../liveMedia
LIVEMEDIA_LIB = $(LIVEMEDIA_DIR)/libliveMedia.$(libliveMedia_LIB_SUFFIX)
GROUPSOCK_DIR = ../groupsock
GROUPSOCK_LIB = $(GROUPSOCK_DIR)/libgroupsock.$(libgroupsock_LIB_SUFFIX)
LOCAL_LIBS =	$(LIVEMEDIA_LIB) $(GROUPSOCK_LIB) \
		$(BASIC_USAGE_ENVIRONMENT_LIB) $(USAGE_ENVIRONMENT_LIB)
LIBS =			$(LOCAL_LIBS) $(LIBS_FOR_CONSOLE_APPLICATION)

live555MediaServer$(EXE):	$(MEDIA_SERVER_OBJS) $(LOCAL_LIBS)
	$(LINK)$@ $(CONSOLE_LINK_OPTS) $(MEDIA_SERVER_OBJS) $(LIBS)
#########Sean	
rtsp_test1$(EXE):	$(rtspMEDIA_SERVER_OBJS) $(LOCAL_LIBS)
	$(LINK)$@ $(CONSOLE_LINK_OPTS) $(rtspMEDIA_SERVER_OBJS) $(LIBS)

clean:
	-rm -rf *.$(OBJ) $(ALL) core *.core *~ include/*~

install: $(MEDIA_SERVER)
	  install -d $(DESTDIR)$(PREFIX)/bin
	  install -m 755 $(MEDIA_SERVER) $(DESTDIR)$(PREFIX)/bin

##### Any additional, platform-specific rules come here:

default: all

AMBABUILD_TOPDIR  = $(word 1, $(subst /app/ipcam, ,$(shell pwd)))
MODULE_NAME		:= mediaServer

export AMBABUILD_TOPDIR

INCLUDES = -I../UsageEnvironment/include -I../groupsock/include \
		-I../liveMedia/include -I../BasicUsageEnvironment/include

-include $(AMBABUILD_TOPDIR)/app/ipcam/rtsp/config.mk


##################### Local dependences:
live555MediaServer,$(CPP):	DynamicRTSPServer.hh version.hh
DynamicRTSPServer.$(CPP):	DynamicRTSPServer.hh

MEDIA_SERVER_OBJS = live555MediaServer.$(OBJ) \
		DynamicRTSPServer.$(OBJ)
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
LIBS =	$(LOCAL_LIBS) $(LIBS_FOR_CONSOLE_APPLICATION)
##################### End of Included LIBS:


##################### Executable apps:
live555MediaServer$(EXE):	$(MEDIA_SERVER_OBJS) $(LOCAL_LIBS)
	@$(LINK)$(EXE_DIR)/$@ $(CONSOLE_LINK_OPTS) $(MEDIA_SERVER_OBJS) $(LIBS)
##################### End of executable apps:


MEDIA_SERVER = live555MediaServer$(EXE)

MODULE_TARGETS = $(MEDIA_SERVER)

EXE_DIR	=	.
$(EXE_DIR):
	@$(MKDIR) $(EXE_DIR)

-include $(AMBABUILD_TOPDIR)/app/ipcam/live_555/rules.mk

