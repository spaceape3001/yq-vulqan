////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/events/MouseEvent.hpp>

namespace yq::tachyon {
    class MouseEnterEvent : public MouseEvent {
        YQ_OBJECT_DECLARE(MouseEnterEvent, MouseEvent)
    public:
    
        struct Param : public MouseEvent::Param {
        };
    
        MouseEnterEvent(Window*, const Param&);
        MouseEnterEvent(WindowID, const Param&);

        virtual ~MouseEnterEvent();
        
        static void init_info();
    };
}

