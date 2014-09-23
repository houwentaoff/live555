MP3_SOURCE_OBJS = MP3FileSource.o MP3Transcoder.o MP3ADU.o MP3ADUdescriptor.o MP3ADUinterleaving.o MP3ADUTranscoder.o MP3StreamState.o MP3Internals.o MP3InternalsHuffman.o MP3InternalsHuffmanTable.o MP3ADURTPSource.o
MPEG_SOURCE_OBJS = MPEG1or2Demux.o MPEG1or2DemuxedElementaryStream.o MPEGVideoStreamFramer.o MPEG1or2VideoStreamFramer.o MPEG1or2VideoStreamDiscreteFramer.o MPEG4VideoStreamFramer.o MPEG4VideoStreamDiscreteFramer.o H264or5VideoStreamFramer.o H264or5VideoStreamDiscreteFramer.o H264VideoStreamFramer.o H264VideoStreamDiscreteFramer.o H265VideoStreamFramer.o H265VideoStreamDiscreteFramer.o MPEGVideoStreamParser.o MPEG1or2AudioStreamFramer.o MPEG1or2AudioRTPSource.o MPEG4LATMAudioRTPSource.o MPEG4ESVideoRTPSource.o MPEG4GenericRTPSource.o $(MP3_SOURCE_OBJS) MPEG1or2VideoRTPSource.o MPEG2TransportStreamMultiplexor.o MPEG2TransportStreamFromPESSource.o MPEG2TransportStreamFromESSource.o MPEG2TransportStreamFramer.o ADTSAudioFileSource.o
H263_SOURCE_OBJS = H263plusVideoRTPSource.o H263plusVideoStreamFramer.o H263plusVideoStreamParser.o
AC3_SOURCE_OBJS = AC3AudioStreamFramer.o AC3AudioRTPSource.o
DV_SOURCE_OBJS = DVVideoStreamFramer.o DVVideoRTPSource.o
MP3_SINK_OBJS = MP3ADURTPSink.o
MPEG_SINK_OBJS = MPEG1or2AudioRTPSink.o $(MP3_SINK_OBJS) MPEG1or2VideoRTPSink.o MPEG4LATMAudioRTPSink.o MPEG4GenericRTPSink.o MPEG4ESVideoRTPSink.o
H263_SINK_OBJS = H263plusVideoRTPSink.o
H264_OR_5_SINK_OBJS = H264or5VideoRTPSink.o H264VideoRTPSink.o H265VideoRTPSink.o
DV_SINK_OBJS = DVVideoRTPSink.o
AC3_SINK_OBJS = AC3AudioRTPSink.o

MISC_SOURCE_OBJS = MediaSource.o FramedSource.o FramedFileSource.o FramedFilter.o ByteStreamFileSource.o ByteStreamMultiFileSource.o ByteStreamMemoryBufferSource.o BasicUDPSource.o DeviceSource.o AudioInputDevice.o WAVAudioFileSource.o $(MPEG_SOURCE_OBJS) $(H263_SOURCE_OBJS) $(AC3_SOURCE_OBJS) $(DV_SOURCE_OBJS) JPEGVideoSource.o AMRAudioSource.o AMRAudioFileSource.o InputFile.o StreamReplicator.o
MISC_SINK_OBJS = MediaSink.o FileSink.o BasicUDPSink.o AMRAudioFileSink.o H264or5VideoFileSink.o H264VideoFileSink.o H265VideoFileSink.o OggFileSink.o $(MPEG_SINK_OBJS) $(H263_SINK_OBJS) $(H264_OR_5_SINK_OBJS) $(DV_SINK_OBJS) $(AC3_SINK_OBJS) VorbisAudioRTPSink.o TheoraVideoRTPSink.o VP8VideoRTPSink.o GSMAudioRTPSink.o JPEGVideoRTPSink.o SimpleRTPSink.o AMRAudioRTPSink.o T140TextRTPSink.o TCPStreamSink.o OutputFile.o
MISC_FILTER_OBJS = uLawAudioFilter.o
TRANSPORT_STREAM_TRICK_PLAY_OBJS = MPEG2IndexFromTransportStream.o MPEG2TransportStreamIndexFile.o MPEG2TransportStreamTrickModeFilter.o

RTP_SOURCE_OBJS = RTPSource.o MultiFramedRTPSource.o SimpleRTPSource.o H261VideoRTPSource.o H264VideoRTPSource.o H265VideoRTPSource.o QCELPAudioRTPSource.o AMRAudioRTPSource.o JPEGVideoRTPSource.o VorbisAudioRTPSource.o TheoraVideoRTPSource.o VP8VideoRTPSource.o
RTP_SINK_OBJS = RTPSink.o MultiFramedRTPSink.o AudioRTPSink.o VideoRTPSink.o TextRTPSink.o
RTP_INTERFACE_OBJS = RTPInterface.o
RTP_OBJS = $(RTP_SOURCE_OBJS) $(RTP_SINK_OBJS) $(RTP_INTERFACE_OBJS)

RTCP_OBJS = RTCP.o rtcp_from_spec.o
RTSP_OBJS = RTSPServer.o RTSPClient.o RTSPCommon.o RTSPServerSupportingHTTPStreaming.o RTSPRegisterSender.o
SIP_OBJS = SIPClient.o

SESSION_OBJS = MediaSession.o ServerMediaSession.o PassiveServerMediaSubsession.o OnDemandServerMediaSubsession.o FileServerMediaSubsession.o MPEG4VideoFileServerMediaSubsession.o H264VideoFileServerMediaSubsession.o H265VideoFileServerMediaSubsession.o H263plusVideoFileServerMediaSubsession.o WAVAudioFileServerMediaSubsession.o AMRAudioFileServerMediaSubsession.o MP3AudioFileServerMediaSubsession.o MPEG1or2VideoFileServerMediaSubsession.o MPEG1or2FileServerDemux.o MPEG1or2DemuxedServerMediaSubsession.o MPEG2TransportFileServerMediaSubsession.o ADTSAudioFileServerMediaSubsession.o DVVideoFileServerMediaSubsession.o AC3AudioFileServerMediaSubsession.o MPEG2TransportUDPServerMediaSubsession.o ProxyServerMediaSession.o

QUICKTIME_OBJS = QuickTimeFileSink.o QuickTimeGenericRTPSource.o
AVI_OBJS = AVIFileSink.o

MATROSKA_FILE_OBJS = MatroskaFile.o MatroskaFileParser.o EBMLNumber.o MatroskaDemuxedTrack.o
MATROSKA_SERVER_MEDIA_SUBSESSION_OBJS = MatroskaFileServerMediaSubsession.o MP3AudioMatroskaFileServerMediaSubsession.o
MATROSKA_RTSP_SERVER_OBJS = MatroskaFileServerDemux.o $(MATROSKA_SERVER_MEDIA_SUBSESSION_OBJS)
MATROSKA_OBJS = $(MATROSKA_FILE_OBJS) $(MATROSKA_RTSP_SERVER_OBJS)

OGG_FILE_OBJS = OggFile.o OggFileParser.o OggDemuxedTrack.o
OGG_SERVER_MEDIA_SUBSESSION_OBJS = OggFileServerMediaSubsession.o
OGG_RTSP_SERVER_OBJS = OggFileServerDemux.o $(OGG_SERVER_MEDIA_SUBSESSION_OBJS)
OGG_OBJS = $(OGG_FILE_OBJS) $(OGG_RTSP_SERVER_OBJS)

MISC_OBJS = DarwinInjector.o BitVector.o StreamParser.o DigestAuthentication.o ourMD5.o Base64.o Locale.o

LIVEMEDIA_LIB_OBJS = Media.o $(MISC_SOURCE_OBJS) $(MISC_SINK_OBJS) $(MISC_FILTER_OBJS) $(RTP_OBJS) $(RTCP_OBJS) $(RTSP_OBJS) $(SIP_OBJS) $(SESSION_OBJS) $(QUICKTIME_OBJS) $(AVI_OBJS) $(TRANSPORT_STREAM_TRICK_PLAY_OBJS) $(MATROSKA_OBJS) $(OGG_OBJS) $(MISC_OBJS)

LIB_OBJS = $(LIVEMEDIA_LIB_OBJS)
