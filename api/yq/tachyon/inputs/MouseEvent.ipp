////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MouseEvent.hpp"

#include <yq/tachyon/event/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MouseEvent)

namespace yq::tachyon {
    
    MouseEventInfo::MouseEventInfo(std::string_view zName, const InputEventInfo& base, const std::source_location& sl) :
        InputEventInfo(zName, base, sl), m_position(p.position), m_buttons(p.buttons), m_modifiers(p.modifiers)
    {
        set(Flag::MOUSE);
    }

    ////////////////////////////////////////////////////////////////////////////

    MouseEvent::MouseEvent(const Param& p) : InputEvent(p)
    {
    }
    
    MouseEvent::~MouseEvent()
    {
    }

    bool  MouseEvent::shift() const
    {
        return m_modifiers(ModifierKey::Shift);
    }
    
    bool  MouseEvent::control() const
    {
        return m_modifiers(ModifierKey::Control);
    }
    
    bool  MouseEvent::alt() const
    {
        return m_modifiers(ModifierKey::Alt);
    }
    
    bool  MouseEvent::caps_lock() const
    {
        return m_modifiers(ModifierKey::CapsLock);
    }
    
    bool  MouseEvent::nums_lock() const
    {
        return m_modifiers(ModifierKey::NumsLock);
    }
    
    bool  MouseEvent::super_key() const
    {
        return m_modifiers(ModifierKey::Super);
    }

    ////////////////////////////////////////////////////////////////////////////

    static void reg_mouse_event()
    {
        {
            auto w = writer<MouseEvent>();
            w.description("Mouse event base class");
            w.property("alt", &MouseEvent::alt).description("TRUE if the alt-key was also pressed");
            w.property("control", &MouseEvent::control).description("TRUE if the control-key was also pressed");
            w.property("shift", &MouseEvent::shift).description("TRUE if the shift-key was also pressed");
            w.property("capslock", &MouseEvent::caps_lock).description("TRUE if the caps lock was active");
            w.property("numslock", &MouseEvent::nums_lock).description("TRUE if the nums lock was active");
            w.property("super", &MouseEvent::super).description("TRUE if the super (OS) key was also pressed");
        }
    }
    
    YQ_INVOKE(reg_mouse_event();)
}
