////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "InputEvent.hpp"
#include <yq/post/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::InputEvent)

namespace yq::tachyon {
    
    InputEventInfo::InputEventInfo(std::string_view zName, const post::EventInfo& base, const std::source_location& sl) :
        post::EventInfo(zName, base, sl)
    {
        set(Flag::INPUT);
    }

    ////////////////////////////////////////////////////////////////////////////

    InputEvent::InputEvent(const Param& p) : post::Event(p), m_viewer(p.viewer), m_modifiers(p.modifiers)
    {
    }
    
    InputEvent::~InputEvent()
    {
    }
    

    bool  InputEvent::alt() const
    {
        return has_alt(m_modifiers);
    }
    
    bool  InputEvent::alt_left() const
    {
        return m_modifiers(ModifierKey::AltLeft);
    }
    
    bool  InputEvent::alt_right() const
    {
        return m_modifiers(ModifierKey::AltRight);
    }

    bool  InputEvent::caps_lock() const
    {
        return has_caps_lock(m_modifiers);
    }

    bool  InputEvent::control() const
    {
        return has_control(m_modifiers);
    }
    
    bool  InputEvent::control_left() const
    {
        return m_modifiers(ModifierKey::ControlLeft);
    }

    bool  InputEvent::control_right() const
    {
        return m_modifiers(ModifierKey::ControlRight);
    }

    bool  InputEvent::num_lock() const
    {
        return has_num_lock(m_modifiers);
    }
    
    bool  InputEvent::scroll_lock() const
    {
        return has_scroll_lock(m_modifiers);
    }

    bool  InputEvent::shift() const
    {
        return has_shift(m_modifiers);
    }
    
    bool  InputEvent::shift_left() const
    {
        return m_modifiers(ModifierKey::ShiftLeft);
    }

    bool  InputEvent::shift_right() const
    {
        return m_modifiers(ModifierKey::ShiftRight);
    }
    
    bool  InputEvent::super() const
    {
        return has_super(m_modifiers);
    }
    
    bool  InputEvent::super_left() const
    {
        return m_modifiers(ModifierKey::SuperLeft);
    }

    bool  InputEvent::super_right() const
    {
        return m_modifiers(ModifierKey::SuperRight);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    static void reg_input_event()
    {
        {
            auto w = writer<InputEvent>();
            w.description("Input event base class");
            w.property("alt", &InputEvent::alt).description("Either alt key was down");
            w.property("alt_left", &InputEvent::alt_left).description("Left alt key was down");
            w.property("alt_right", &InputEvent::alt_right).description("Right alt key was down");
            w.property("caps_lock", &InputEvent::caps_lock).description("TRUE if the caps lock was active");
            w.property("control", &InputEvent::control).description("Either control key was down");
            w.property("control_left", &InputEvent::control_left).description("Left control key was down");
            w.property("control_right", &InputEvent::control_right).description("Right control key was down");
            w.property("num_lock", &InputEvent::num_lock).description("TRUE if the num lock was active");
            w.property("scroll_lock", &InputEvent::scroll_lock).description("TRUE if the scroll lock was active");
            w.property("shift", &InputEvent::shift).description("Either shift key was down");
            w.property("shift_left", &InputEvent::shift_left).description("Left shift key was down");
            w.property("shift_right", &InputEvent::shift_right).description("Right shift key was down");
            w.property("super", &InputEvent::super).description("Either super (OS) key was down");
            w.property("super_left", &InputEvent::super).description("Left super (OS) key was down");
            w.property("super_right", &InputEvent::super).description("Right super (OS) key was down");
        }
    }
    
    YQ_INVOKE(reg_input_event();)
}
