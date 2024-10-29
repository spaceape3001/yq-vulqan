////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "KeyEvent.hpp"

#include <yq/tachyon/event/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::KeyEvent)

namespace yq::tachyon {
    
    KeyEventInfo::KeyEventInfo(std::string_view zName, const InputEventInfo& base, const std::source_location& sl) :
        InputEventInfo(zName, base, sl)
    {
        set(Flag::KEYBOARD);
    }

    ////////////////////////////////////////////////////////////////////////////

    KeyEvent::KeyEvent(const Param& p) : InputEvent(p), m_modifiers(p.modifiers)
    {
    }
    
    KeyEvent::~KeyEvent()
    {
    }

    bool  KeyEvent::shift() const
    {
        return m_modifiers(ModifierKey::Shift);
    }
    
    bool  KeyEvent::control() const
    {
        return m_modifiers(ModifierKey::Control);
    }
    
    bool  KeyEvent::alt() const
    {
        return m_modifiers(ModifierKey::Alt);
    }
    
    bool  KeyEvent::caps_lock() const
    {
        return m_modifiers(ModifierKey::CapsLock);
    }
    
    bool  KeyEvent::nums_lock() const
    {
        return m_modifiers(ModifierKey::NumsLock);
    }
    
    bool  KeyEvent::super_key() const
    {
        return m_modifiers(ModifierKey::Super);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    static void reg_keyboard_event()
    {
        {
            auto w = writer<KeyEvent>();
            w.description("Keyboard event base class");
            w.property("alt", &KeyEvent::alt).description("TRUE if the alt-key was also pressed");
            w.property("control", &KeyEvent::control).description("TRUE if the control-key was also pressed");
            w.property("shift", &KeyEvent::shift).description("TRUE if the shift-key was also pressed");
            w.property("capslock", &KeyEvent::caps_lock).description("TRUE if the caps lock was active");
            w.property("numslock", &KeyEvent::nums_lock).description("TRUE if the nums lock was active");
            w.property("super", &KeyEvent::super).description("TRUE if the super (OS) key was also pressed");
        }
    }
    
    YQ_INVOKE(reg_keyboard_event();)
}
