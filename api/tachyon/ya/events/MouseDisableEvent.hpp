////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/events/WindowEvent.hpp>

namespace yq::tachyon {
    class MouseDisableEvent : public WindowEvent {
        YQ_OBJECT_DECLARE(MouseDisableEvent, WindowEvent)
    public:
    
        struct Param : public WindowEvent::Param {
        };
    
        MouseDisableEvent(Window*, const Param& p = {});
        virtual ~MouseDisableEvent();
        
        static void init_info();
    };
}
