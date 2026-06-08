////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/os/KeyboardState.hpp>
#include <yq/tachyon/os/MouseState.hpp>
#include <yq/tachyon/os/WindowState.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/typedef/window.hpp>

namespace yq::tachyon {
    class WindowSnap : public TachyonSnap {
        YQ_OBJECT_DECLARE(WindowSnap, TachyonSnap)
    public:
        WindowState             window;
        MouseState              mouse;
        KeyboardState           keyboard;
        double                  time = 0.; // suspect....
        
        WindowSnap();
        ~WindowSnap();
        static void init_meta();
    };
    
    class WindowData : public TachyonData {
        YQ_OBJECT_DECLARE(WindowData, TachyonData)
    public:
        WindowData();
        ~WindowData();
        static void init_meta();
    };
}
