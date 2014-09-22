MP3_SOURCE_OBJS = MP3FileSource.$(OBJ) MP3Transcoder.$(OBJ) MP3ADU.$(OBJ) MP3ADUdescriptor.$(OBJ) MP3ADUinterleaving.$(OBJ) MP3ADUTranscoder.$(OBJ) MP3StreamState.$(OBJ) MP3Internals.$(OBJ) MP3InternalsHuffman.$(OBJ) MP3InternalsHuffmanTable.$(OBJ) MP3ADURTPSource.$(OBJ)
MPEG_SOURCE_OBJS = MPEG1or2Demux.$(OBJ) MPEG1or2DemuxedElementaryStream.$(OBJ) MPEGVideoStreamFramer.$(OBJ) MPEG1or2VideoStreamFramer.$(OBJ) MPEG1or2VideoStreamDiscreteFramer.$(OBJ) MPEG4VideoStreamFramer.$(OBJ) MPEG4VideoStreamDiscreteFramer.$(OBJ) H264or5VideoStreamFramer.$(OBJ) H264or5VideoStreamDiscreteFramer.$(OBJ) H264VideoStreamFramer.$(OBJ) H264VideoStreamDiscreteFramer.$(OBJ) H265VideoStreamFramer.$(OBJ) H265VideoStreamDiscreteFramer.$(OBJ) MPEGVideoStreamParser.$(OBJ) MPEG1or2AudioStreamFramer.$(OBJ) MPEG1or2AudioRTPSource.$(OBJ) MPEG4LATMAudioRTPSource.$(OBJ) MPEG4ESVideoRTPSource.$(OBJ) MPEG4GenericRTPSource.$(OBJ) $(MP3_SOURCE_OBJS) MPEG1or2VideoRTPSource.$(OBJ) MPEG2TransportStreamMultiplexor.$(OBJ) MPEG2TransportStreamFromPESSource.$(OBJ) MPEG2TransportStreamFromESSource.$(OBJ) MPEG2TransportStreamFramer.$(OBJ) ADTSAudioFileSource.$(OBJ)
H263_SOURCE_OBJS = H263plusVideoRTPSource.$(OBJ) H263plusVideoStreamFramer.$(OBJ) H263plusVideoStreamParser.$(OBJ)
AC3_SOURCE_OBJS = AC3AudioStreamFramer.$(OBJ) AC3AudioRTPSource.$(OBJ)
DV_SOURCE_OBJS = DVVideoStreamFramer.$(OBJ) DVVideoRTPSource.$(OBJ)
MP3_SINK_OBJS = MP3ADURTPSink.$(OBJ)
MPEG_SINK_OBJS = MPEG1or2AudioRTPSink.$(OBJ) $(MP3_SINK_OBJS) MPEG1or2VideoRTPSink.$(OBJ) MPEG4LATMAudioRTPSink.$(OBJ) MPEG4GenericRTPSink.$(OBJ) MPEG4ESVideoRTPSink.$(OBJ)
H263_SINK_OBJS = H263plusVideoRTPSink.$(OBJ)
H264_OR_5_SINK_OBJS = H264or5VideoRTPSink.$(OBJ) H264VideoRTPSink.$(OBJ) H265VideoRTPSink.$(OBJ)
DV_SINK_OBJS = DVVideoRTPSink.$(OBJ)
AC3_SINK_OBJS = AC3AudioRTPSink.$(OBJ)

MISC_SOURCE_OBJS = MediaSource.$(OBJ) FramedSource.$(OBJ) FramedFileSource.$(OBJ) FramedFilter.$(OBJ) ByteStreamFileSource.$(OBJ) ByteStreamMultiFileSource.$(OBJ) ByteStreamMemoryBufferSource.$(OBJ) BasicUDPSource.$(OBJ) DeviceSource.$(OBJ) AudioInputDevice.$(OBJ) WAVAudioFileSource.$(OBJ) $(MPEG_SOURCE_OBJS) $(H263_SOURCE_OBJS) $(AC3_SOURCE_OBJS) $(DV_SOURCE_OBJS) JPEGVideoSource.$(OBJ) AMRAudioSource.$(OBJ) AMRAudioFileSource.$(OBJ) InputFile.$(OBJ) StreamReplicator.$(OBJ)
MISC_SINK_OBJS = MediaSink.$(OBJ) FileSink.$(OBJ) BasicUDPSink.$(OBJ) AMRAudioFileSink.$(OBJ) H264or5VideoFileSink.$(OBJ) H264VideoFileSink.$(OBJ) H265VideoFileSink.$(OBJ) OggFileSink.$(OBJ) $(MPEG_SINK_OBJS) $(H263_SINK_OBJS) $(H264_OR_5_SINK_OBJS) $(DV_SINK_OBJS) $(AC3_SINK_OBJS) VorbisAudioRTPSink.$(OBJ) TheoraVideoRTPSink.$(OBJ) VP8VideoRTPSink.$(OBJ) GSMAudioRTPSink.$(OBJ) JPEGVideoRTPSink.$(OBJ) SimpleRTPSink.$(OBJ) AMRAudioRTPSink.$(OBJ) T140TextRTPSink.$(OBJ) TCPStreamSink.$(OBJ) OutputFile.$(OBJ)
MISC_FILTER_OBJS = uLawAudioFilter.$(OBJ)
TRANSPORT_STREAM_TRICK_PLAY_OBJS = MPEG2IndexFromTransportStream.$(OBJ) MPEG2TransportStreamIndexFile.$(OBJ) MPEG2TransportStreamTrickModeFilter.$(OBJ)

RTP_SOURCE_OBJS = RTPSource.$(OBJ) MultiFramedRTPSource.$(OBJ) SimpleRTPSource.$(OBJ) H261VideoRTPSource.$(OBJ) H264VideoRTPSource.$(OBJ) H265VideoRTPSource.$(OBJ) QCELPAudioRTPSource.$(OBJ) AMRAudioRTPSource.$(OBJ) JPEGVideoRTPSource.$(OBJ) VorbisAudioRTPSource.$(OBJ) TheoraVideoRTPSource.$(OBJ) VP8VideoRTPSource.$(OBJ)
RTP_SINK_OBJS = RTPSink.$(OBJ) MultiFramedRTPSink.$(OBJ) AudioRTPSink.$(OBJ) VideoRTPSink.$(OBJ) TextRTPSink.$(OBJ)
RTP_INTERFACE_OBJS = RTPInterface.$(OBJ)
RTP_OBJS = $(RTP_SOURCE_OBJS) $(RTP_SINK_OBJS) $(RTP_INTERFACE_OBJS)

RTCP_OBJS = RTCP.$(OBJ) rtcp_from_spec.$(OBJ)
RTSP_OBJS = RTSPServer.$(OBJ) RTSPClient.$(OBJ) RTSPCommon.$(OBJ) RTSPServerSupportingHTTPStreaming.$(OBJ) RTSPRegisterSender.$(OBJ)
SIP_OBJS = SIPClient.$(OBJ)

SESSION_OBJS = MediaSession.$(OBJ) ServerMediaSession.$(OBJ) PassiveServerMediaSubsession.$(OBJ) OnDemandServerMediaSubsession.$(OBJ) FileServerMediaSubsession.$(OBJ) MPEG4VideoFileServerMediaSubsession.$(OBJ) H264VideoFileServerMediaSubsession.$(OBJ) H265VideoFileServerMediaSubsession.$(OBJ) H263plusVideoFileServerMediaSubsession.$(OBJ) WAVAudioFileServerMediaSubsession.$(OBJ) AMRAudioFileServerMediaSubsession.$(OBJ) MP3AudioFileServerMediaSubsession.$(OBJ) MPEG1or2VideoFileServerMediaSubsession.$(OBJ) MPEG1or2FileServerDemux.$(OBJ) MPEG1or2DemuxedServerMediaSubsession.$(OBJ) MPEG2TransportFileServerMediaSubsession.$(OBJ) ADTSAudioFileServerMediaSubsession.$(OBJ) DVVideoFileServerMediaSubsession.$(OBJ) AC3AudioFileServerMediaSubsession.$(OBJ) MPEG2TransportUDPServerMediaSubsession.$(OBJ) ProxyServerMediaSession.$(OBJ)

QUICKTIME_OBJS = QuickTimeFileSink.$(OBJ) QuickTimeGenericRTPSource.$(OBJ)
AVI_OBJS = AVIFileSink.$(OBJ)

MATROSKA_FILE_OBJS = MatroskaFile.$(OBJ) MatroskaFileParser.$(OBJ) EBMLNumber.$(OBJ) MatroskaDemuxedTrack.$(OBJ)
MATROSKA_SERVER_MEDIA_SUBSESSION_OBJS = MatroskaFileServerMediaSubsession.$(OBJ) MP3AudioMatroskaFileServerMediaSubsession.$(OBJ)
MATROSKA_RTSP_SERVER_OBJS = MatroskaFileServerDemux.$(OBJ) $(MATROSKA_SERVER_MEDIA_SUBSESSION_OBJS)
MATROSKA_OBJS = $(MATROSKA_FILE_OBJS) $(MATROSKA_RTSP_SERVER_OBJS)

OGG_FILE_OBJS = OggFile.$(OBJ) OggFileParser.$(OBJ) OggDemuxedTrack.$(OBJ)
OGG_SERVER_MEDIA_SUBSESSION_OBJS = OggFileServerMediaSubsession.$(OBJ)
OGG_RTSP_SERVER_OBJS = OggFileServerDemux.$(OBJ) $(OGG_SERVER_MEDIA_SUBSESSION_OBJS)
OGG_OBJS = $(OGG_FILE_OBJS) $(OGG_RTSP_SERVER_OBJS)

MISC_OBJS = DarwinInjector.$(OBJ) BitVector.$(OBJ) StreamParser.$(OBJ) DigestAuthentication.$(OBJ) ourMD5.$(OBJ) Base64.$(OBJ) Locale.$(OBJ)

LIVEMEDIA_LIB_OBJS = Media.$(OBJ) $(MISC_SOURCE_OBJS) $(MISC_SINK_OBJS) $(MISC_FILTER_OBJS) $(RTP_OBJS) $(RTCP_OBJS) $(RTSP_OBJS) $(SIP_OBJS) $(SESSION_OBJS) $(QUICKTIME_OBJS) $(AVI_OBJS) $(TRANSPORT_STREAM_TRICK_PLAY_OBJS) $(MATROSKA_OBJS) $(OGG_OBJS) $(MISC_OBJS)

LIB_OBJS = $(LIVEMEDIA_LIB_OBJS)
