////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/events/WindowEvent.hpp>

namespace yq::tachyon {
    class WindowCursorCaptureEvent : public WindowEvent {
        YQ_OBJECT_DECLARE(WindowCursorCaptureEvent, WindowEvent)
    public:
    
        struct Param : public WindowEvent::Param {
        };
    
        WindowCursorCaptureEvent(Window*, const Param& p = {});
        virtual ~WindowCursorCaptureEvent();
        
        static void init_info();
    };
}
