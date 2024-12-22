////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/events/WindowEvent.hpp>

namespace yq::tachyon {
    class CursorCaptureEvent : public WindowEvent {
        YQ_OBJECT_DECLARE(CursorCaptureEvent, WindowEvent)
    public:
    
        struct Param : public WindowEvent::Param {
        };
    
        CursorCaptureEvent(Window*, const Param& p = {});
        virtual ~CursorCaptureEvent();
        
        static void init_info();
    };
}
