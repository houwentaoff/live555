default: all

MODULE_NAME		:= mediaServer

INCLUDES  		:= -I../UsageEnvironment/include -I../groupsock/include \
		-I../liveMedia/include -I../BasicUsageEnvironment/include
#LOCAL_LIBS       := -L../UsageEnvironment -L../groupsock -L../liveMedia \
	-L../BasicUsageEnvironment -lpthread

include ../lib.rules

all:live555MediaServer rtsp_test1

##################### Local dependences:
live555MediaServer.cpp:	DynamicRTSPServer.hh version.hh
DynamicRTSPServer.cpp:	DynamicRTSPServer.hh

MEDIA_SERVER_OBJS = live555MediaServer.o \
		DynamicRTSPServer.o
##################### End of local dependences:

live555MediaServer:	$(MEDIA_SERVER_OBJS)

clean:
	@$(ECHO) '  [Clean $(MODULE_NAME)]:'
	@$(RM) *.o live555MediaServer rtsp_test1

USAGE_ENVIRONMENT_LIB = ../UsageEnvironment/libUsageEnvironment.a
BASIC_USAGE_ENVIRONMENT_LIB = ../BasicUsageEnvironment/libBasicUsageEnvironment.a
LIVEMEDIA_LIB = ../liveMedia/libliveMedia.a
GROUPSOCK_LIB = ../groupsock/libgroupsock.a
LOCAL_LIBS = $(LIVEMEDIA_LIB) $(GROUPSOCK_LIB) \
			$(BASIC_USAGE_ENVIRONMENT_LIB) \
			$(USAGE_ENVIRONMENT_LIB)

LD = $(SYS_LIBS) -pthread 


live555MediaServer:	$(MEDIA_SERVER_OBJS) $(LOCAL_LIBS)
	$(CXX) $^ -o $@ $(LD)

rtsp_test1:	rtsp_test1.o $(LOCAL_LIBS)
	@$(CXX) $^ -o $@ $(LOCAL_LIBS) $(LD)
