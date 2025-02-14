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
        MouseScrollEvent(const Header&, ModifierKeys, const Vector2D&, MouseButtons, const Vector2D& delta);
        
        static void init_info();
        
        const Vector2D& delta() const { return m_delta; }
        double          delta_x() const { return m_delta.x; }
        double          delta_y() const { return m_delta.y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MouseScrollEvent(const MouseScrollEvent& cp, const Header&);
        virtual ~MouseScrollEvent();
        
    private:
        Vector2D    m_delta;
        
        MouseScrollEvent(const MouseScrollEvent&) = delete;
        MouseScrollEvent(MouseScrollEvent&&) = delete;
        MouseScrollEvent& operator=(const MouseScrollEvent&) = delete;
        MouseScrollEvent& operator=(MouseScrollEvent&&) = delete;
    };
}

