////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/events/WindowEvent.hpp>

namespace yq::tachyon {
    class WindowCursorDisableEvent : public WindowEvent {
        YQ_OBJECT_DECLARE(WindowCursorDisableEvent, WindowEvent)
    public:
    
        struct Param : public WindowEvent::Param {
        };
    
        WindowCursorDisableEvent(Window*, const Param& p = {});
        virtual ~WindowCursorDisableEvent();
        
        static void init_info();
    };
}
