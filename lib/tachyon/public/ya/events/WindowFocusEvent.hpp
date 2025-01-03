////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/events/WindowEvent.hpp>

namespace yq::tachyon {
    class WindowFocusEvent : public WindowEvent {
        YQ_OBJECT_DECLARE(WindowFocusEvent, WindowEvent)
    public:
    
        struct Param : public WindowEvent::Param {
        };
    
        WindowFocusEvent(Window*, const Param& p = {});
        virtual ~WindowFocusEvent();
        
        static void init_info();
    };
}
