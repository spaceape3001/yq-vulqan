////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/os/KeyboardState.hpp>
#include <yt/os/MouseState.hpp>
#include <yt/os/WindowState.hpp>

namespace yq::tachyon {
    struct ViewerState {
        WindowState             window;
        MouseState              mouse;
        KeyboardState           keyboard;
        double                  time = 0.;
    };
}
