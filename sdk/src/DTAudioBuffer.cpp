/// Copyright 2010-2012 4kdownload.com (developers@4kdownload.com)
/**
    This file is part of 4k Download.

    4k Download is free software; you can redistribute it and/or modify
    it under the terms of the one of two licenses as you choose:

    1. GNU GENERAL PUBLIC LICENSE Version 3
    (See file COPYING.GPLv3 for details).

    2. 4k Download Commercial License
    (Send request to developers@4kdownload.com for details).
   
*/


#include <openmedia/DTHeaders.h>

/// \file   DTAudioBuffer.cpp

#include <openmedia/DTAudioBuffer.h>
#include "DTAudioBufferImpl.h"
#include "DTAudioBufferSameFormat.h"

namespace openmedia {

void audio_buffer::push_back(const audio_data * _AudioData)
{
    return impl()->push_back(_AudioData);
}

audio_data_ptr audio_buffer::pop_front(int _SamplesCount)
{
    return impl()->pop_front(_SamplesCount);
}

void audio_buffer::push_back_raw(const uint8_t * _Data, size_t _DataSize)
{
    return impl()->push_back_raw(_Data, _DataSize);
}

audio_format_ptr audio_buffer::get_output_audio_format() const
{
    return impl()->get_output_audio_format();
}

int audio_buffer::get_samples_count() const
{
    return impl()->get_samples_count();
}

audio_buffer::~audio_buffer()
{
    delete m_pImpl;
}

audio_buffer::audio_buffer(audio_buffer::Impl * _Impl): m_pImpl(_Impl)
{
    DT_STRONG_ASSERT(NULL != _Impl);
}

audio_buffer_ptr audio_buffer::create(AudioBufferType _BufferType, const audio_format * _AudioFormat)
{
    audio_buffer * audioBuffer = NULL;
    switch (_BufferType)
    {
    case audio_buffer_SameFormat:
        audioBuffer = new audio_buffer_same_format(_AudioFormat);
        break;
    default:
        DT_ASSERT(false);
        break;
    }
    return audio_buffer_ptr(audioBuffer);
}

audio_buffer::invalid_format::invalid_format()
{
    m_msg = "Invalid audio format";
}

}
