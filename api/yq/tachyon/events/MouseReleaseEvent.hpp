////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/events/MouseEvent.hpp>

namespace yq::tachyon {
    class MouseReleaseEvent : public MouseEvent {
        YQ_OBJECT_DECLARE(MouseReleaseEvent, MouseEvent)
    public:
    
        struct Param : public MouseEvent::Param {
            MouseButton     button      = {};
        };
    
        MouseReleaseEvent(const Param&);

        MouseButton         button() const { return m_button; }
        virtual ~MouseReleaseEvent();
        
        bool    left() const;
        bool    right() const;
        bool    middle() const;
        
        static void init_info();
        
    private:
        MouseButton     m_button;
    };
}
