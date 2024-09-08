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
    static constexpr const size_t   MAX_FRAMES_IN_FLIGHT    = 3;
    
    //! Minimum number of descriptors
    static constexpr const uint32_t MIN_DESCRIPTOR_COUNT    = 1024;
}
