////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <cstddef>
#include <cstdint>

namespace yq::tachyon {
    //! Max bytes we'll entertain for push constants
    static constexpr const size_t   MAX_PUSH                = 256;
    
    //! Maximum count of frames in flight (for presentation)
    static constexpr const uint32_t MAX_FRAMES_IN_FLIGHT    = 3;
    
    static constexpr const uint32_t MIN_FRAMES_IN_FLIGHT    = 2;

    //! Minimum number of descriptors
    static constexpr const uint32_t MIN_DESCRIPTOR_COUNT    = 1024;
    
    //! Default wait timeout (ns)
    static constexpr const uint64_t DEFAULT_WAIT_TIMEOUT    = 99'999'999ULL;
}
