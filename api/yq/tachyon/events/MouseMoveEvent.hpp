////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/events/MouseEvent.hpp>

namespace yq::tachyon {
    class MouseMoveEvent : public MouseEvent {
        YQ_OBJECT_DECLARE(MouseMoveEvent, MouseEvent)
    public:
    
        struct Param : public MouseEvent::Param {
        };
    
        MouseMoveEvent(Window*, const Param&);
        MouseMoveEvent(WindowID, const Param&);

        virtual ~MouseMoveEvent();
        
        static void init_info();
    };
}

