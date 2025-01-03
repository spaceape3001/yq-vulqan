////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/events/MouseEvent.hpp>

namespace yq::tachyon {
    class MouseScrollEvent : public MouseEvent {
        YQ_OBJECT_DECLARE(MouseScrollEvent, MouseEvent)
    public:
    
        struct Param : public MouseEvent::Param {
            Vector2D    delta;
        };
    
        MouseScrollEvent(Window*, const Param&);
        MouseScrollEvent(WindowID, const Param&);

        virtual ~MouseScrollEvent();
        
        static void init_info();
        
        const Vector2D& delta() const { return m_delta; }
        double          delta_x() const { return m_delta.x; }
        double          delta_y() const { return m_delta.y; }
        
    private:
        const Vector2D    m_delta;
    };
}

