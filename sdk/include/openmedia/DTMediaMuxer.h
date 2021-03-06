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


/// \file   DTMediaMuxer.h

#ifndef _DTMEDIAMUXER_H_INCLUDED_
#define _DTMEDIAMUXER_H_INCLUDED_
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>

#include <openmedia/DTTypes.h>
#include <openmedia/DTDeclareImpl.h>
#include <openmedia/DTCommon.h>
#include <openmedia/DTPacket.h>
#include <openmedia/DTError.h>

namespace openmedia {

class media_muxer;
typedef boost::shared_ptr<media_muxer> media_muxer_ptr;

namespace errors {

struct write_packet: virtual dt_error {};
struct create_file: virtual dt_error {};

} // namespace errors

/// \class  media_muxer
class _OPENMEDIASDK_API media_muxer: interface_base
{
    DT_DECLARE_IMPL2(media_muxer);
public:
    void write_packet(media_packet_ptr _MediaPacket);
    void close();
    virtual ~media_muxer() = 0;

protected:
    media_muxer(media_muxer::Impl * _Impl);
    void reset_impl(media_muxer::Impl * _Impl);

private:
    media_muxer::Impl * m_pImpl;
};

class _OPENMEDIASDK_API media_muxer_creator
{
public:
    static media_muxer_ptr create(const char * FormatName, const char * FileName);

#if defined(DT_CONFIG_HAVE_UTF16_OPEN) && (1 == DT_CONFIG_HAVE_UTF16_OPEN)
    static media_muxer_ptr create(const char * FormatName, const wchar_t * Filename);
#endif

};

} // namespace openmedia

#endif // #ifndef _DTMEDIAMUXER_H_INCLUDED_
