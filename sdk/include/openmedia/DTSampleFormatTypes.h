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


/// \file   DTSampleFormatTypes.h

#ifndef _DTSAMPLEFORMATTYPES_H_INCLUDED_
#define _DTSAMPLEFORMATTYPES_H_INCLUDED_
#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

namespace openmedia {

/**
 * all in native-endian format
 */
enum dt_sample_format_t {
    DT_SAMPLE_FMT_NONE = -1,
    DT_SAMPLE_FMT_U8,              ///< unsigned 8 bits
    DT_SAMPLE_FMT_S16,             ///< signed 16 bits
    DT_SAMPLE_FMT_S32,             ///< signed 32 bits
    DT_SAMPLE_FMT_FLT,             ///< float
    DT_SAMPLE_FMT_DBL,             ///< double
    DT_SAMPLE_FMT_NB               ///< Number of sample formats. DO NOT USE if dynamically linking to libavcodec
};

}

#endif // #ifndef _DTSAMPLEFORMATTYPES_H_INCLUDED_