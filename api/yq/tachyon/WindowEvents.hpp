////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/glfw/Window.hpp>
#include <yq/tachyon/glfw/Joystick.hpp>
#include <yq/tachyon/glfw/Monitor.hpp>

namespace yq::tachyon {

    //  NOTE NOT THE GENERAL EVENTS... will map to the others (later)

    // callback for non-window specific events
    struct Window::Events {
        virtual void    connected(Joystick){}
        virtual void    disconnected(Joystick){}

        virtual void    connected(Monitor){}
        virtual void    disconnected(Monitor){}
        virtual ~Events(){}
    };
}
