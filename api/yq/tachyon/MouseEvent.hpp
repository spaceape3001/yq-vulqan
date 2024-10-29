////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/InputEvent.hpp>
#include <yq/tachyon/MouseButton.hpp>
#include <yq/tachyon/ModifierKey.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {
    class MouseEventInfo : public InputEventInfo {
    public:
        MouseEventInfo(std::string_view zName, const InputEventInfo& base, const std::source_location& sl=std::source_location::current());
    protected:
    };


    class MouseEvent : public InputEvent {
        YQ_OBJECT_INFO(MouseEventInfo)
        YQ_OBJECT_DECLARE(MouseEvent, InputEvent)
    public:
    
        struct Param : public InputEvent::Param {
            Vector2D        position    = {};
            MouseButtons    buttons     = {};
            ModifierKeys    modifiers   = {};
        };
    
        //  EVENT TODO
    
        virtual ~MouseEvent();

        //! Modifiers (either in the callback, or last recorded)
        ModifierKeys        modifiers() const { return m_modifiers; }
        
        bool                alt() const;
        bool                alt_left() const;
        bool                alt_right() const;
        
        bool                caps_lock() const;

        bool                control() const;
        bool                control_left() const;
        bool                control_right() const;

        bool                num_lock() const;

        bool                scroll_lock() const;

        bool                shift() const;
        bool                shift_left() const;
        bool                shift_right() const;

        bool                super() const;
        bool                super_left() const;
        bool                super_right() const;
        
        MouseButtons        buttons() const { return m_buttons; }
        
        //! Screen coordinate position
        const Vector2D&     position() const { return m_position; }
        double              x() const { return m_position.x; }
        double              y() const { return m_position.y; }
        
    protected:
        MouseEvent(const Param&);
        
    private:
        Vector2D        m_position;
        MouseButtons    m_buttons;
        ModifierKeys    m_modifiers;
    };
}
