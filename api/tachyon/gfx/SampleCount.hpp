////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <cstdint>
#include <yq/core/Flags.hpp>

namespace yq::tachyon {
    enum class SampleCount : uint8_t {
        One         = 0,
        Two         = 1,
        Four        = 2,
        Eight       = 3,
        Sixteen     = 4,
        ThirtyTwo   = 5,
        SixtyFour   = 6
    };
    
    using SampleCountFlags  = Flags<SampleCount,uint32_t>;
}
