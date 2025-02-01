////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/events/WindowEvent.hpp>

namespace yq::tachyon {
    class WindowDestroyEvent : public WindowEvent {
        YQ_OBJECT_DECLARE(WindowDestroyEvent, WindowEvent)
    public:
    
        struct Param : public WindowEvent::Param {
        };
    
        WindowDestroyEvent(Window*, const Param& p = {});
        virtual ~WindowDestroyEvent();
        
        static void init_info();
    };
}
