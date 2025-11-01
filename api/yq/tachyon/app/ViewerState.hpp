////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/os/KeyboardState.hpp>
#include <yq/tachyon/os/MouseState.hpp>
#include <yq/tachyon/os/WindowState.hpp>

namespace yq::tachyon {
    struct ViewerState {
        WindowState             window;
        MouseState              mouse;
        KeyboardState           keyboard;
        double                  time = 0.;
    };
}
