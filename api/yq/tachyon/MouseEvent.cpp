////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MouseEvent.hpp"

#include <yq/post/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MouseEvent)

namespace yq::tachyon {
    
    MouseEventInfo::MouseEventInfo(std::string_view zName, const InputEventInfo& base, const std::source_location& sl) :
        InputEventInfo(zName, base, sl)
    {
        set(Flag::MOUSE);
    }

    ////////////////////////////////////////////////////////////////////////////

    MouseEvent::MouseEvent(const Param& p) : InputEvent(p), m_position(p.position), m_buttons(p.buttons), m_modifiers(p.modifiers)
    {
    }
    
    MouseEvent::~MouseEvent()
    {
    }


    bool  MouseEvent::alt() const
    {
        return has_alt(m_modifiers);
    }
    
    bool  MouseEvent::alt_left() const
    {
        return m_modifiers(ModifierKey::AltLeft);
    }
    
    bool  MouseEvent::caps_lock() const
    {
        return has_caps_lock(m_modifiers);
    }

    bool  MouseEvent::control() const
    {
        return has_control(m_modifiers);
    }
    
    bool  MouseEvent::control_left() const
    {
        return m_modifiers(ModifierKey::ControlLeft);
    }

    bool  MouseEvent::control_right() const
    {
        return m_modifiers(ModifierKey::ControlRight);
    }

    bool  MouseEvent::num_lock() const
    {
        return has_num_lock(m_modifiers);
    }
    
    bool  MouseEvent::scroll_lock() const
    {
        return has_scroll_lock(m_modifiers);
    }

    bool  MouseEvent::shift() const
    {
        return has_shift(m_modifiers);
    }
    
    bool  MouseEvent::shift_left() const
    {
        return m_modifiers(ModifierKey::ShiftLeft);
    }

    bool  MouseEvent::shift_right() const
    {
        return m_modifiers(ModifierKey::ShiftRight);
    }
    
    bool  MouseEvent::super() const
    {
        return has_super(m_modifiers);
    }
    
    bool  MouseEvent::super_left() const
    {
        return m_modifiers(ModifierKey::SuperLeft);
    }

    bool  MouseEvent::super_right() const
    {
        return m_modifiers(ModifierKey::SuperRight);
    }

    ////////////////////////////////////////////////////////////////////////////

    static void reg_mouse_event()
    {
        {
            auto w = writer<MouseEvent>();
            w.description("Mouse event base class");
            w.property("alt", &MouseEvent::alt).description("Either alt key was down");
            w.property("alt_left", &MouseEvent::alt_left).description("Left alt key was down");
            w.property("alt_right", &MouseEvent::alt_right).description("Right alt key was down");
            w.property("caps_lock", &MouseEvent::caps_lock).description("TRUE if the caps lock was active");
            w.property("control", &MouseEvent::control).description("Either control key was down");
            w.property("control_left", &MouseEvent::control_left).description("Left control key was down");
            w.property("control_right", &MouseEvent::control_right).description("Right control key was down");
            w.property("num_lock", &MouseEvent::num_lock).description("TRUE if the num lock was active");
            w.property("position", &MouseEvent;:position).description("Mouse (cursor) position");
            w.property("scroll_lock", &MouseEvent::scroll_lock).description("TRUE if the scroll lock was active");
            w.property("shift", &MouseEvent::shift).description("Either shift key was down");
            w.property("shift_left", &MouseEvent::shift_left).description("Left shift key was down");
            w.property("shift_right", &MouseEvent::shift_right).description("Right shift key was down");
            w.property("super", &MouseEvent::super).description("Either super (OS) key was down");
            w.property("super_left", &MouseEvent::super).description("Left super (OS) key was down");
            w.property("super_right", &MouseEvent::super).description("Right super (OS) key was down");
            w.property("x", &MouseEvent::x).description("Mouse (cursor) X position");
            w.property("y", &MouseEvent::y).description("Mouse (cursor) Y position");
        }
    }
    
    YQ_INVOKE(reg_mouse_event();)
}
