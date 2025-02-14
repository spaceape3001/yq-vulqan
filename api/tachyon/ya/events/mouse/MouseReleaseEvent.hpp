////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/events/MouseEvent.hpp>

namespace yq::tachyon {
    class MouseReleaseEvent : public MouseEvent {
        YQ_OBJECT_DECLARE(MouseReleaseEvent, MouseEvent)
    public:
    
        MouseReleaseEvent(const Header&, ModifierKeys, const Vector2D&, MouseButtons, MouseButton);

        MouseButton         button() const { return m_button; }

        
        bool    left() const;
        bool    right() const;
        bool    middle() const;
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        static void init_info();

    protected:
        MouseReleaseEvent(const MouseReleaseEvent&, const Header&);
        virtual ~MouseReleaseEvent();
        
    private:
        MouseButton     m_button;
        
        MouseReleaseEvent(const MouseReleaseEvent&) = delete;
        MouseReleaseEvent(MouseReleaseEvent&&) = delete;
        MouseReleaseEvent& operator=(const MouseReleaseEvent&) = delete;
        MouseReleaseEvent& operator=(MouseReleaseEvent&&) = delete;
    };
}
