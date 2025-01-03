////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/events/WindowEvent.hpp>

namespace yq::tachyon {
    class WindowDefocusEvent : public WindowEvent {
        YQ_OBJECT_DECLARE(WindowDefocusEvent, WindowEvent)
    public:
    
        struct Param : public WindowEvent::Param {
        };
    
        WindowDefocusEvent(Window*, const Param& p = {});
        virtual ~WindowDefocusEvent();
        
        static void init_info();
    };
}
