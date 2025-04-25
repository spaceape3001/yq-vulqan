////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/os/KeyboardState.hpp>
#include <tachyon/os/MouseState.hpp>
#include <tachyon/os/WindowState.hpp>

namespace yq::tachyon {
    struct ViewerState {
        WindowState             window;
        MouseState              mouse;
        KeyboardState           keyboard;
        double                  time = 0.;
    };
}
