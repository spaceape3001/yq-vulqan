////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/events/MouseEvent.hpp>

namespace yq::tachyon {
    class MouseEnterEvent : public MouseEvent {
        YQ_OBJECT_DECLARE(MouseEnterEvent, MouseEvent)
    public:
    
        struct Param : public MouseEvent::Param {
        };
    
        MouseEnterEvent(const Param&);

        virtual ~MouseEnterEvent();
        
        static void init_info();
    };
}

