////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/events/InputEvent.hpp>
#include <yt/os/MouseButton.hpp>
#include <yt/os/ModifierKey.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {
    class MouseEvent : public InputEvent {
        YQ_OBJECT_DECLARE(MouseEvent, InputEvent)
    public:
    
        MouseButtons        buttons() const { return m_buttons; }
        
        //! Screen coordinate position
        const Vector2D&     position() const { return m_position; }
        double              x() const { return m_position.x; }
        double              y() const { return m_position.y; }
        
        bool    left_button() const;
        bool    right_button() const;
        bool    middle_button() const;
        
        static void init_info();
        
    protected:
        MouseEvent(const Header&, ModifierKeys, const Vector2D&, MouseButtons);
        MouseEvent(const MouseEvent&, const Header&);
        virtual ~MouseEvent();
        
    private:
        Vector2D        m_position;
        MouseButtons    m_buttons;
    };
}
