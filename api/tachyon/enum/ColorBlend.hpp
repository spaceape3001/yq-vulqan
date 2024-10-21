////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <cstdint>

namespace yq::tachyon {
    enum class ColorBlend : uint8_t {
        Disabled    = 0,
        Additive,
        AlphaBlend
    };
}