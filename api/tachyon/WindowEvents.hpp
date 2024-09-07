////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/Window.hpp>
#include <yq-vulqan/glfw/Joystick.hpp>
#include <yq-vulqan/glfw/Monitor.hpp>

namespace yq::tachyon {
    // callback for non-window specific events
    struct Window::Events {
        virtual void    connected(Joystick){}
        virtual void    disconnected(Joystick){}

        virtual void    connected(Monitor){}
        virtual void    disconnected(Monitor){}
        virtual ~Events(){}
    };
}
