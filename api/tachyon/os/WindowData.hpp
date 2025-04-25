////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/os/KeyboardState.hpp>
#include <tachyon/os/MouseState.hpp>
#include <tachyon/os/WindowState.hpp>
#include <yt/api/TachyonData.hpp>
#include <tachyon/typedef/window.hpp>

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
