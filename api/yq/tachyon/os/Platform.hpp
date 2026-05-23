////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/meta/MetaBinder.hpp>

namespace yq::tachyon {


    enum class Platform : uint8_t {
        None    = 0,
        GLFW
        
        //  Add these as ... implemented
        // MACOS
        // SDL
        // WAYLAND
        // WIN32
        // X11
    };
}
YQ_TYPE_DECLARE(yq::tachyon::Platform)
