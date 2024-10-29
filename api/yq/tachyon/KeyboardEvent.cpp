////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "KeyboardEvent.hpp"

#include <yq/post/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::KeyboardEvent)

namespace yq::tachyon {
    
    KeyboardEventInfo::KeyboardEventInfo(std::string_view zName, const InputEventInfo& base, const std::source_location& sl) :
        InputEventInfo(zName, base, sl)
    {
        set(Flag::KEYBOARD);
    }

    ////////////////////////////////////////////////////////////////////////////

    KeyboardEvent::KeyboardEvent(const Param& p) : InputEvent(p), m_modifiers(p.modifiers)
    {
    }
    
    KeyboardEvent::~KeyboardEvent()
    {
    }

    bool  KeyboardEvent::alt() const
    {
        return has_alt(m_modifiers);
    }
    
    bool  KeyboardEvent::alt_left() const
    {
        return m_modifiers(ModifierKey::AltLeft);
    }
    
    bool  KeyboardEvent::caps_lock() const
    {
        return has_caps_lock(m_modifiers);
    }

    bool  KeyboardEvent::control() const
    {
        return has_control(m_modifiers);
    }
    
    bool  KeyboardEvent::control_left() const
    {
        return m_modifiers(ModifierKey::ControlLeft);
    }

    bool  KeyboardEvent::control_right() const
    {
        return m_modifiers(ModifierKey::ControlRight);
    }

    bool  KeyboardEvent::num_lock() const
    {
        return has_num_lock(m_modifiers);
    }
    
    bool  KeyboardEvent::scroll_lock() const
    {
        return has_scroll_lock(m_modifiers);
    }

    bool  KeyboardEvent::shift() const
    {
        return has_shift(m_modifiers);
    }
    
    bool  KeyboardEvent::shift_left() const
    {
        return m_modifiers(ModifierKey::ShiftLeft);
    }

    bool  KeyboardEvent::shift_right() const
    {
        return m_modifiers(ModifierKey::ShiftRight);
    }
    
    bool  KeyboardEvent::super() const
    {
        return has_super(m_modifiers);
    }
    
    bool  KeyboardEvent::super_left() const
    {
        return m_modifiers(ModifierKey::SuperLeft);
    }

    bool  KeyboardEvent::super_right() const
    {
        return m_modifiers(ModifierKey::SuperRight);
    }

    ////////////////////////////////////////////////////////////////////////////

    static void reg_keyboard_event()
    {
        {
            auto w = writer<KeyboardEvent>();
            w.description("Keyboard event base class");
            w.property("alt", &KeyboardEvent::alt).description("Either alt key was down");
            w.property("alt_left", &KeyboardEvent::alt_left).description("Left alt key was down");
            w.property("alt_right", &KeyboardEvent::alt_right).description("Right alt key was down");
            w.property("caps_lock", &KeyboardEvent::caps_lock).description("TRUE if the caps lock was active");
            w.property("control", &KeyboardEvent::control).description("Either control key was down");
            w.property("control_left", &KeyboardEvent::control_left).description("Left control key was down");
            w.property("control_right", &KeyboardEvent::control_right).description("Right control key was down");
            w.property("num_lock", &KeyboardEvent::num_lock).description("TRUE if the num lock was active");
            w.property("scroll_lock", &KeyboardEvent::scroll_lock).description("TRUE if the scroll lock was active");
            w.property("shift", &KeyboardEvent::shift).description("Either shift key was down");
            w.property("shift_left", &KeyboardEvent::shift_left).description("Left shift key was down");
            w.property("shift_right", &KeyboardEvent::shift_right).description("Right shift key was down");
            w.property("super", &KeyboardEvent::super).description("Either super (OS) key was down");
            w.property("super_left", &KeyboardEvent::super).description("Left super (OS) key was down");
            w.property("super_right", &KeyboardEvent::super).description("Right super (OS) key was down");
        }
    }
    
    YQ_INVOKE(reg_keyboard_event();)
}
