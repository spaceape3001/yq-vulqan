////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/KeyboardState.hpp>
#include <yq/tachyon/api/MouseState.hpp>
#include <yq/tachyon/api/WindowState.hpp>

namespace yq::tachyon {
    struct ViewerState {
        WindowState             window;
        MouseState              mouse;
        KeyboardState           keyboard;
        double                  time = 0.;
    };
}
