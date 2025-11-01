////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/MouseEvent.hpp>

namespace yq::tachyon {
    class MousePressEvent : public MouseEvent {
        YQ_OBJECT_DECLARE(MousePressEvent, MouseEvent)
    public:
    
        MousePressEvent(const Header&, ModifierKeys, const Vector2D&, MouseButtons, MouseButton);
        
        //! Scan code from the operating system (no interpretation)
        MouseButton         button() const { return m_button; }
        
        bool    left() const;
        bool    right() const;
        bool    middle() const;
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        static void init_meta();
        
    protected:
        MousePressEvent(const MousePressEvent&, const Header&);
        virtual ~MousePressEvent();
        
    private:
        MouseButton m_button;
        
        MousePressEvent(const MousePressEvent&) = delete;
        MousePressEvent(MousePressEvent&&) = delete;
        MousePressEvent& operator=(const MousePressEvent&) = delete;
        MousePressEvent& operator=(MousePressEvent&&) = delete;
        
    };
}
