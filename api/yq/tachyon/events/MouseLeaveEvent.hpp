////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/events/MouseEvent.hpp>

namespace yq::tachyon {
    class MouseLeaveEvent : public MouseEvent {
        YQ_OBJECT_DECLARE(MouseLeaveEvent, MouseEvent)
    public:
    
        struct Param : public MouseEvent::Param {
        };
    
        MouseLeaveEvent(const Param&);

        virtual ~MouseLeaveEvent();
        
        static void init_info();
    };
}

