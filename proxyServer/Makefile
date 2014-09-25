default: all

MODULE_NAME		:= ProxyServer

INCLUDES = -I../UsageEnvironment/include -I../groupsock/include -I../liveMedia/include -I../BasicUsageEnvironment/include

include ../lib.rules

all: live555ProxyServer

PROXY_SERVER_OBJS = live555ProxyServer.o

LOCAL_LIBS = ../liveMedia/libliveMedia.a ../groupsock/libgroupsock.a \
			 ../BasicUsageEnvironment/libBasicUsageEnvironment.a \
			 ../UsageEnvironment/libUsageEnvironment.a
LINK_EXTRA_LIBS = -lpthread
LIBS = $(LOCAL_LIBS)
LD   = $(SYS_LIBS) $(LINK_EXTRA_LIBS)

live555ProxyServer$(EXE):	$(PROXY_SERVER_OBJS) $(LOCAL_LIBS)
	@$(CXX) $^ -o $@ $(LD)

clean:
	@$(ECHO) '  [Clean $(MODULE_NAME)]:'
	@$(RM) *.o live555ProxyServer 
