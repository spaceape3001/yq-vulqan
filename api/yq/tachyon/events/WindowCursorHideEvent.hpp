////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/events/WindowEvent.hpp>

namespace yq::tachyon {
    class WindowCursorHideEvent : public WindowEvent {
        YQ_OBJECT_DECLARE(WindowCursorHideEvent, WindowEvent)
    public:
    
        struct Param : public WindowEvent::Param {
        };
    
        WindowCursorHideEvent(Window*, const Param& p = {});
        virtual ~WindowCursorHideEvent();
        
        static void init_info();
    };
}
