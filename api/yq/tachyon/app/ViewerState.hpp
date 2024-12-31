////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/desktop/KeyboardState.hpp>
#include <yq/tachyon/desktop/MouseState.hpp>
#include <yq/tachyon/desktop/WindowState.hpp>

namespace yq::tachyon {
    struct ViewerState {
        WindowState             window;
        MouseState              mouse;
        KeyboardState           keyboard;
        double                  time = 0.;
    };
}
