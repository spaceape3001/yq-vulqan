////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/input/InputEvent.hpp>
#include <tachyon/enum/MouseButton.hpp>
#include <tachyon/enum/ModifierKey.hpp>
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
            Vector2D        position    = NAN;
            MouseButtons    buttons     = {};
            ModifierKeys    modifiers   = {};
        };
    
        //  EVENT TODO
    
        virtual ~MouseEvent();

        //! Modifiers (either in the callback, or last recorded)
        ModifierKeys        modifiers() const { return m_modifiers; }
        
        bool                shift() const;
        bool                control() const;
        bool                alt() const;
        bool                caps_lock() const;
        bool                nums_lock() const;
        bool                super_key() const;
        
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
