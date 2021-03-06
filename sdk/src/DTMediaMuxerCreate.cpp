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


#include <openmedia/DTMediaMuxer.h>
#include "./ffmpeg/DTFFMediaMuxer.h"
#include "DTRAWFile.h"

#include <string>
#include <vector>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>

namespace openmedia {

media_muxer_ptr media_muxer_creator::create(const char * FormatName, const char * FileName)
{
    ::std::vector< ::std::string > result;
    ::std::string fmt(FormatName);
    boost::algorithm::split(result, fmt, boost::algorithm::is_any_of("/"));
    
    if ( !result.size() )
    {
        BOOST_THROW_EXCEPTION( errors::invalid_operation() );            
        return media_muxer_ptr();
    }

    if (result[0] == "openmedia")
    {
        if (result.size() < 2)
        {
            BOOST_THROW_EXCEPTION( errors::invalid_operation() );            
            return media_muxer_ptr();
        }

        if (result[1] == "ppm")
        {
            return media_muxer_ptr( new raw_file(FileName) );
        }
    }

    if (result[0] == "ffmpeg")
    {
        if (result.size() < 2)
        {
            BOOST_THROW_EXCEPTION( errors::invalid_operation() );            
            return media_muxer_ptr();
        }

        return media_muxer_ptr( new ff_simple_media_muxer(result[1].c_str(), FileName) );
    }

    BOOST_THROW_EXCEPTION( errors::invalid_operation() );            
    return media_muxer_ptr();
}

#if defined(DT_CONFIG_HAVE_UTF16_OPEN) && (1 == DT_CONFIG_HAVE_UTF16_OPEN)
media_muxer_ptr media_muxer_creator::create(const char * FormatName, const wchar_t * FileName)
{
    return media_muxer_ptr( );
}
#endif

} // namespace openmedia
