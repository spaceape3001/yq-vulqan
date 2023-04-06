////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/host/Window.hpp>
#include <tachyon/host/Joystick.hpp>
#include <tachyon/host/Monitor.hpp>

namespace yq {
    namespace tachyon {
        // callback for non-window specific events
        struct Window::Events {
            virtual void    connected(Joystick){}
            virtual void    disconnected(Joystick){}

            virtual void    connected(Monitor){}
            virtual void    disconnected(Monitor){}
            virtual ~Events(){}
        };
    }
}
