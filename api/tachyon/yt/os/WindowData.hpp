////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/os/KeyboardState.hpp>
#include <yt/os/MouseState.hpp>
#include <yt/os/WindowState.hpp>
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
