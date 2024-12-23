////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/events/WindowEvent.hpp>

namespace yq::tachyon {
    class WindowCursorNormalEvent : public WindowEvent {
        YQ_OBJECT_DECLARE(WindowCursorNormalEvent, WindowEvent)
    public:
    
        struct Param : public WindowEvent::Param {
        };
    
        WindowCursorNormalEvent(Window*, const Param& p = {});
        virtual ~WindowCursorNormalEvent();
        
        static void init_info();
    };
}
