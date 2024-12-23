////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/events/InputEvent.hpp>
#include <yq/tachyon/enum/MouseButton.hpp>
#include <yq/tachyon/enum/ModifierKey.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {
    class MouseEventInfo : public InputEventInfo {
    public:
        MouseEventInfo(std::string_view zName, InputEventInfo& base, const std::source_location& sl=std::source_location::current());
    protected:
    };


    class MouseEvent : public InputEvent {
        YQ_OBJECT_INFO(MouseEventInfo)
        YQ_OBJECT_DECLARE(MouseEvent, InputEvent)
    public:
    
        struct Param : public InputEvent::Param {
            Vector2D        position    = {};
            MouseButtons    buttons     = {};
        };
    
        //  EVENT TODO
    
        virtual ~MouseEvent();
        
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
        MouseEvent(Window*, const Param&);
        MouseEvent(WindowID, const Param&);
        
    private:
        const Vector2D        m_position;
        const MouseButtons    m_buttons;
    };
}
