////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/events/MouseEvent.hpp>

namespace yq::tachyon {
    class MouseLeaveEvent : public MouseEvent {
        YQ_OBJECT_DECLARE(MouseLeaveEvent, MouseEvent)
    public:
    
        struct Param : public MouseEvent::Param {
        };
    
        MouseLeaveEvent(Window*, const Param&);
        MouseLeaveEvent(WindowID, const Param&);

        virtual ~MouseLeaveEvent();
        
        static void init_info();
    };
}

