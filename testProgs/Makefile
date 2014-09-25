default: all

MODULE_NAME		:= testProgs
MODULE_TARGETS   = $(ALL_APPS)

INCLUDES 		 = -I../UsageEnvironment/include -I../groupsock/include -I../liveMedia/include -I../BasicUsageEnvironment/include

include ../lib.rules

default: all

MULTICAST_STREAMER_APPS = testMP3Streamer testMPEG1or2VideoStreamer testMPEG1or2AudioVideoStreamer testMPEG2TransportStreamer testMPEG4VideoStreamer testH264VideoStreamer testH265VideoStreamer testDVVideoStreamer testWAVAudioStreamer testAMRAudioStreamer testMKVStreamer testOggStreamer vobStreamer
MULTICAST_RECEIVER_APPS = testMP3Receiver testMPEG1or2VideoReceiver testMPEG2TransportReceiver sapWatch
MULTICAST_MISC_APPS = testRelay testReplicator
MULTICAST_APPS = $(MULTICAST_STREAMER_APPS) $(MULTICAST_RECEIVER_APPS) $(MULTICAST_MISC_APPS)
UNICAST_STREAMER_APPS = testOnDemandRTSPServer
UNICAST_RECEIVER_APPS = testRTSPClient openRTSP playSIP
UNICAST_APPS = $(UNICAST_STREAMER_APPS) $(UNICAST_RECEIVER_APPS)
MISC_APPS = testMPEG1or2Splitter testMPEG1or2ProgramToTransportStream testH264VideoToTransportStream testH265VideoToTransportStream MPEG2TransportStreamIndexer testMPEG2TransportStreamTrickPlay registerRTSPStream
ALL_APPS = $(MULTICAST_APPS) $(UNICAST_APPS) $(MISC_APPS)

all: $(MODULE_TARGETS)

extra:	testGSMStreamer

MP3_STREAMER_OBJS = testMP3Streamer.o
MP3_RECEIVER_OBJS = testMP3Receiver.o
RELAY_OBJS = testRelay.o
REPLICATOR_OBJS = testReplicator.o
MPEG_1OR2_SPLITTER_OBJS = testMPEG1or2Splitter.o
MPEG_1OR2_VIDEO_STREAMER_OBJS = testMPEG1or2VideoStreamer.o
MPEG_1OR2_VIDEO_RECEIVER_OBJS = testMPEG1or2VideoReceiver.o
MPEG2_TRANSPORT_RECEIVER_OBJS = testMPEG2TransportReceiver.o
MPEG_1OR2_AUDIO_VIDEO_STREAMER_OBJS = testMPEG1or2AudioVideoStreamer.o
MPEG2_TRANSPORT_STREAMER_OBJS = testMPEG2TransportStreamer.o
MPEG4_VIDEO_STREAMER_OBJS = testMPEG4VideoStreamer.o
H264_VIDEO_STREAMER_OBJS = testH264VideoStreamer.o
H265_VIDEO_STREAMER_OBJS = testH265VideoStreamer.o
DV_VIDEO_STREAMER_OBJS = testDVVideoStreamer.o
WAV_AUDIO_STREAMER_OBJS = testWAVAudioStreamer.o
AMR_AUDIO_STREAMER_OBJS	= testAMRAudioStreamer.o
ON_DEMAND_RTSP_SERVER_OBJS	= testOnDemandRTSPServer.o
MKV_STREAMER_OBJS	= testMKVStreamer.o
OGG_STREAMER_OBJS	= testOggStreamer.o
VOB_STREAMER_OBJS	= vobStreamer.o
TEST_RTSP_CLIENT_OBJS    = testRTSPClient.o
OPEN_RTSP_OBJS    = openRTSP.o playCommon.o
PLAY_SIP_OBJS     = playSIP.o playCommon.o
SAP_WATCH_OBJS = sapWatch.o
MPEG_1OR2_PROGRAM_TO_TRANSPORT_STREAM_OBJS = testMPEG1or2ProgramToTransportStream.o
H264_VIDEO_TO_TRANSPORT_STREAM_OBJS = testH264VideoToTransportStream.o
H265_VIDEO_TO_TRANSPORT_STREAM_OBJS = testH265VideoToTransportStream.o
MPEG2_TRANSPORT_STREAM_INDEXER_OBJS = MPEG2TransportStreamIndexer.o
MPEG2_TRANSPORT_STREAM_TRICK_PLAY_OBJS = testMPEG2TransportStreamTrickPlay.o
REGISTER_RTSP_STREAM_OBJS = registerRTSPStream.o

GSM_STREAMER_OBJS = testGSMStreamer.o testGSMEncoder.o

openRTSP.$(CPP):	playCommon.hh
playCommon.$(CPP):	playCommon.hh
playSIP.$(CPP):		playCommon.hh


LOCAL_LIBS      = ../liveMedia/libliveMedia.a ../groupsock/libgroupsock.a \
			 ../BasicUsageEnvironment/libBasicUsageEnvironment.a \
			 ../UsageEnvironment/libUsageEnvironment.a
LINK_EXTRA_LIBS = -lpthread
LIBS 			= $(LOCAL_LIBS) 
LD  			= $(SYS_LIBS) $(LINK_EXTRA_LIBS)

testMP3Streamer:	$(MP3_STREAMER_OBJS) $(LOCAL_LIBS)
	@$(CXX) $^ -o $@ $(LD)
testMP3Receiver:	$(MP3_RECEIVER_OBJS) $(LOCAL_LIBS)
	@$(CXX) $^ -o $@ $(LD)
testRelay:	$(RELAY_OBJS) $(LOCAL_LIBS)
	@$(CXX) $^ -o $@ $(LD)
testReplicator:	$(REPLICATOR_OBJS) $(LOCAL_LIBS)
	@$(CXX) $^ -o $@ $(LD)
testMPEG1or2Splitter:	$(MPEG_1OR2_SPLITTER_OBJS) $(LOCAL_LIBS)
	@$(CXX) $^ -o $@ $(LD)
testMPEG1or2VideoStreamer:	$(MPEG_1OR2_VIDEO_STREAMER_OBJS) $(LOCAL_LIBS)
	@$(CXX) $^ -o $@ $(LD)
testMPEG1or2VideoReceiver:	$(MPEG_1OR2_VIDEO_RECEIVER_OBJS) $(LOCAL_LIBS)
	@$(CXX) $^ -o $@ $(LD)
testMPEG1or2AudioVideoStreamer:	$(MPEG_1OR2_AUDIO_VIDEO_STREAMER_OBJS) $(LOCAL_LIBS)
	@$(CXX) $^ -o $@ $(LD)
testMPEG2TransportStreamer:	$(MPEG2_TRANSPORT_STREAMER_OBJS) $(LOCAL_LIBS)
	@$(CXX) $^ -o $@ $(LD)
testMPEG2TransportReceiver:	$(MPEG2_TRANSPORT_RECEIVER_OBJS) $(LOCAL_LIBS)
	@$(CXX) $^ -o $@ $(LD)
testMPEG4VideoStreamer:	$(MPEG4_VIDEO_STREAMER_OBJS) $(LOCAL_LIBS)
	@$(CXX) $^ -o $@ $(LD)
testH264VideoStreamer:	$(H264_VIDEO_STREAMER_OBJS) $(LOCAL_LIBS)
	@$(CXX) $^ -o $@ $(LD)
testH265VideoStreamer:	$(H265_VIDEO_STREAMER_OBJS) $(LOCAL_LIBS)
	@$(CXX) $^ -o $@ $(LD)
testDVVideoStreamer:	$(DV_VIDEO_STREAMER_OBJS) $(LOCAL_LIBS)
	@$(CXX) $^ -o $@ $(LD)
testWAVAudioStreamer:	$(WAV_AUDIO_STREAMER_OBJS) $(LOCAL_LIBS)
	@$(CXX) $^ -o $@ $(LD)
testAMRAudioStreamer:	$(AMR_AUDIO_STREAMER_OBJS) $(LOCAL_LIBS)
	@$(CXX) $^ -o $@ $(LD)
testOnDemandRTSPServer:	$(ON_DEMAND_RTSP_SERVER_OBJS) $(LOCAL_LIBS)
	@$(CXX) $^ -o $@ $(LD)
testMKVStreamer:	$(MKV_STREAMER_OBJS) $(LOCAL_LIBS)
	@$(CXX) $^ -o $@ $(LD)
testOggStreamer:	$(OGG_STREAMER_OBJS) $(LOCAL_LIBS)
	@$(CXX) $^ -o $@ $(LD)
vobStreamer:	$(VOB_STREAMER_OBJS) $(LOCAL_LIBS)
	@$(CXX) $^ -o $@ $(LD)
testRTSPClient:	$(TEST_RTSP_CLIENT_OBJS) $(LOCAL_LIBS)
	@$(CXX) $^ -o $@ $(LD)
openRTSP:	$(OPEN_RTSP_OBJS) $(LOCAL_LIBS)
	@$(CXX) $^ -o $@ $(LD)
playSIP:	$(PLAY_SIP_OBJS) $(LOCAL_LIBS)
	@$(CXX) $^ -o $@ $(LD)
sapWatch:	$(SAP_WATCH_OBJS) $(LOCAL_LIBS)
	@$(CXX) $^ -o $@ $(LD)
testMPEG1or2ProgramToTransportStream:	$(MPEG_1OR2_PROGRAM_TO_TRANSPORT_STREAM_OBJS) $(LOCAL_LIBS)
	@$(CXX) $^ -o $@ $(LD)
testH264VideoToTransportStream:	$(H264_VIDEO_TO_TRANSPORT_STREAM_OBJS) $(LOCAL_LIBS)
	@$(CXX) $^ -o $@ $(LD)
testH265VideoToTransportStream:	$(H265_VIDEO_TO_TRANSPORT_STREAM_OBJS) $(LOCAL_LIBS)
	@$(CXX) $^ -o $@ $(LD)
MPEG2TransportStreamIndexer:	$(MPEG2_TRANSPORT_STREAM_INDEXER_OBJS) $(LOCAL_LIBS)
	@$(CXX) $^ -o $@ $(LD)
testMPEG2TransportStreamTrickPlay:	$(MPEG2_TRANSPORT_STREAM_TRICK_PLAY_OBJS) $(LOCAL_LIBS)
	@$(CXX) $^ -o $@ $(LD)
registerRTSPStream:	$(REGISTER_RTSP_STREAM_OBJS) $(LOCAL_LIBS)
	@$(CXX) $^ -o $@ $(LD)
testGSMStreamer:	$(GSM_STREAMER_OBJS) $(LOCAL_LIBS)
	@$(CXX) $^ -o $@ $(LD)

clean:
	@$(ECHO) '  [Clean $(MODULE_NAME)]:'
	@$(RM) *.o $(MODULE_TARGETS) $(LIB_OBJS)

