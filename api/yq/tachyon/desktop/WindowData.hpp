////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/desktop/KeyboardState.hpp>
#include <yq/tachyon/desktop/MouseState.hpp>
#include <yq/tachyon/desktop/WindowState.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/typedef/window.hpp>

namespace yq::tachyon {
    struct WindowSnap : public TachyonSnap {
        WindowState             window;
        MouseState              mouse;
        KeyboardState           keyboard;
        double                  time = 0.;
    };
    
    struct WindowData : public TachyonData {
    };
}
