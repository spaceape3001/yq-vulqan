////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/preamble.hpp>
#include <math/color/RGB.hpp>
#include <math/shape/Size2.hpp>

namespace yq::tachyon {
    struct VideoMode {
        Size2I      size            = {};
        RGB3I       bits            = {};
        int         refresh_rate    = 0;
        VideoMode(){}
        VideoMode(const GLFWvidmode&);
        constexpr bool    operator==(const VideoMode&) const noexcept = default;
    };
}
