TEMPLATE = lib
TARGET = sdkmedia

include ($$SOURCE_TREE/common.pri)

QT -= core gui

CONFIG += staticlib

DEFINES += URDL_DISABLE_SSL
#DEFINES += URDL_HEADER_ONLY
win32 {
    DEFINES += _WIN32_WINNT=0x0501
    DEFINES += WIN32_LEAN_AND_MEAN=1
}

INCLUDEPATH += \
    include \
    $$SOURCE_TREE/3rdparty/urdl/include
                
HEADERS += \
    src/DTAudioBufferImpl.h \
    src/DTAudioBufferSameFormat.h \
    src/DTAudioDataImpl.h \
    src/DTAudioDecoderImpl.h \
    src/DTAudioDecoderInfoCommon.h \
    src/DTAudioDecoderInfoImpl.h \
    src/DTAudioEncoderImpl.h \
    src/DTAudioFormatImpl.h \
    src/DTCodecExtraDataImpl.h \
    src/DTCommonCodecExtraData.h \
    src/DTCommonPacket.h \
    src/DTDecoderImpl.h \
    src/DTDecoderInfoImpl.h \
    src/DTLameEncoder.h \
    src/DTLameEncoderImpl.h \
    src/DTMediaMuxerImpl.h \
    src/DTPacketImpl.h \
    src/DTVideoDecoderInfoImpl.h \
    src/ffmpeg/DTFFAlloc.h \
    src/ffmpeg/DTFFAudioDecoder.h \
    src/ffmpeg/DTFFCodec.h \
    src/ffmpeg/DTFFDecoder.h \
    src/ffmpeg/DTFFDecoderInfo.h \
    src/ffmpeg/DTFFHeader.h \
    src/ffmpeg/DTFFMediaSplitter.h \
    src/ffmpeg/DTFFStreamInfo.h \
    src/ffmpeg/DTFFFileInfoImpl.h \
    src/ffmpeg/DTFFFileInfo.h \    
    include/openmedia/DTAdditionalSettings.h \
    include/openmedia/DTAudioBuffer.h \
    include/openmedia/DTAudioData.h \
    include/openmedia/DTAudioDataCommon.h \
    include/openmedia/DTAudioDataTimed.h \
    include/openmedia/DTAudioDecoder.h \
    include/openmedia/DTAudioDecoderInfo.h \
    include/openmedia/DTAudioEncoder.h \
    include/openmedia/DTAudioFormat.h \
    include/openmedia/DTAudioUtils.h \
    include/openmedia/DTCodec.h \
    include/openmedia/DTCodecExtraData.h \
    include/openmedia/DTCodecTypes.h \
    include/openmedia/DTConfig.h \
    include/openmedia/DTDecoder.h \
    include/openmedia/DTDecoderInfo.h \
    include/openmedia/DTHeaders.h \
    include/openmedia/DTMediaMuxer.h \
    include/openmedia/DTMediaTypes.h \
    include/openmedia/DTMP3File.h \
    include/openmedia/DTPacket.h \
    include/openmedia/DTPixFormatTypes.h \
    include/openmedia/DTPlatform.h \
    include/openmedia/DTSampleFormatTypes.h \
    include/openmedia/DTTiming.h \
    include/openmedia/DTTypes.h \
    include/openmedia/DTVideoDecoderInfo.h \
    include/openmedia/DTStreamInfo.h \
    include/openmedia/DTFileInfo.h \
    include/openmedia/DTMediaSplitter.h	\
    src/DTFileInfoImpl.h \
    src/DTMediaSplitterImpl.h \
    src/DTStreamInfoImpl.h \
    src/ffmpeg/DTFFPacket.h \
    src/ffmpeg/DTFFUTF8File.h \
    src/ffmpeg/DTFFResampleConvert.h \
    src/ffmpeg/DTFFSampleFmtConvert.h \
    include/openmedia/DTAudioConvert.h \
    src/DTVideoDataImpl.h \
    src/ffmpeg/DTFFVideoDataImpl.h \
    src/ffmpeg/DTFFVideoData.h \
    src/ffmpeg/DTFFPicture.h \
    src/ffmpeg/DTFFMediaMuxer.h \
    include/openmedia/DTVideoData.h \
    include/openmedia/DTVideoDataTimed.h \
    include/openmedia/DTVideoDecoder.h \
    include/openmedia/DTVideoFormat.h \
    src/ffmpeg/DTFFVideoDecoder.h \
    src/DTVideoDecoderImpl.h \
    src/DTRAWFile.h \
    src/DTPictureConvertImpl.h \
    src/ffmpeg/DTFFPictureConvertImpl.h \
    src/ffmpeg/DTFFPictureConvert.h
                
SOURCES += \
    src/DTAdditionalSettings.cpp \
    src/DTAudioBuffer.cpp \
    src/DTAudioBufferSameFormat.cpp \
    src/DTAudioData.cpp \
    src/DTAudioDataCommon.cpp \
    src/DTAudioDecoder.cpp \
    src/DTAudioDecoderInfo.cpp \
    src/DTAudioEncoder.cpp \
    src/DTAudioFormat.cpp \
    src/DTCodec.cpp \
    src/DTCodecExtraData.cpp \
    src/DTCommonCodecExtraData.cpp \
    src/DTCommonPacket.cpp \
    src/DTDecoder.cpp \
    src/DTDecoderInfo.cpp \
    src/DTError.cpp \
    src/DTLameEncoder.cpp \
    src/DTLameEncoderDetails.cpp \
    src/DTMediaMuxer.cpp \
    src/DTMP3File.cpp \
    src/DTPacket.cpp \
    src/DTPacketImpl.cpp \
    src/DTSimpleMediaParser.cpp \
    src/DTVideoDecoderInfo.cpp \
    src/ffmpeg/DTFFAlloc.cpp \
    src/ffmpeg/DTFFAudioDecoder.cpp \
    src/ffmpeg/DTFFCodec.cpp \
    src/ffmpeg/DTFFDecoder.cpp \
    src/ffmpeg/DTFFDecoderInfo.cpp \
    src/ffmpeg/DTFFFileInfo.cpp \
    src/ffmpeg/DTFFFileInfoImpl.cpp \
    src/ffmpeg/DTFFMediaSplitter.cpp \
    src/ffmpeg/DTFFStreamInfo.cpp \
    src/DTFileInfo.cpp \
    src/DTStreamInfo.cpp \
    src/DTMediaSplitter.cpp \
    src/ffmpeg/DTFFPacket.cpp \
    src/ffmpeg/DTFFUTF8File.cpp \
    src/ffmpeg/DTFFUtils.cpp \
    src/DTAudioConvert.cpp \
    src/ffmpeg/DTFFResampleConvert.cpp \
    src/ffmpeg/DTFFSampleFmtConvert.cpp \
    src/DTAudioPacket.cpp \
    src/DTAudioDataCreate.cpp \
    src/DTPacketSpecial.cpp \
    src/DTAudioEncoderSettingsImpl.cpp \
    src/DTAudioEncoderQueue.cpp \
    src/DTMediaSplitterCreate.cpp \
    src/ffmpeg/DTFFMediaMuxer.cpp \
    src/ffmpeg/DTFFPicture.cpp \
    src/ffmpeg/DTFFVideoData.cpp \
    src/ffmpeg/DTFFVideoDataImpl.cpp \
    src/DTVideoFormat.cpp \
    src/DTVideoData.cpp \
    src/DTVideoDataImpl.cpp \
    src/DTVideoDecoderCreate.cpp \
    src/DTVideoDecoder.cpp \
    src/ffmpeg/DTFFVideoDecoder.cpp \
    src/DTMediaMuxerCreate.cpp \
    src/DTVideo2Mp3.cpp \
    src/DTRAWFile.cpp \
    src/DTPictureConvert.cpp \
    src/ffmpeg/DTFFPictureConvert.cpp \
    src/ffmpeg/DTFFPictureConvertImpl.cpp \
    src/DTPictureConvertCreate.cpp
    
DEPENDENCY_LIBS = \
    sdkcommon \
    urdl

include ($$SOURCE_TREE/dependencies.pri)
   