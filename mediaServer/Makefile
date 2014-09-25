default: all

MODULE_NAME		 := mediaServer

INCLUDES  		 = -I../UsageEnvironment/include -I../groupsock/include \
		-I../liveMedia/include -I../BasicUsageEnvironment/include

include ../lib.rules

all:live555MediaServer rtsp_test1

live555MediaServer.cpp:	DynamicRTSPServer.hh version.hh
DynamicRTSPServer.cpp:	DynamicRTSPServer.hh

MEDIA_SERVER_OBJS = live555MediaServer.o \
		DynamicRTSPServer.o

live555MediaServer:	$(MEDIA_SERVER_OBJS)

LOCAL_LIBS        = ../liveMedia/libliveMedia.a ../groupsock/libgroupsock.a \
					../BasicUsageEnvironment/libBasicUsageEnvironment.a \
					../UsageEnvironment/libUsageEnvironment.a

LD = $(SYS_LIBS) -pthread 

live555MediaServer:	$(MEDIA_SERVER_OBJS) $(LOCAL_LIBS)
	$(CXX) $^ -o $@ $(LD)

rtsp_test1:	rtsp_test1.o $(LOCAL_LIBS)
	@$(CXX) $^ -o $@ $(LD)

clean:
	@$(ECHO) '  [Clean $(MODULE_NAME)]:'
	@$(RM) *.o live555MediaServer rtsp_test1
