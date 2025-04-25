////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Enum.hpp>
#include <yq/meta/InfoBinder.hpp>

namespace yq::tachyon {


    YQ_ENUM(Platform, , 
        None    = 0,
        GLFW
        
        //  Add these as ... implemented
        // MACOS
        // SDL
        // WAYLAND
        // WIN32
        // X11
    )
}
YQ_TYPE_DECLARE(yq::tachyon::Platform)
