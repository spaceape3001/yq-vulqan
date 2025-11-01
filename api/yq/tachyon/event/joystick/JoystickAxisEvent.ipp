////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/event/joystick/JoystickAxisEvent.hpp>
#include <yq/tachyon/api/EventMetaWriter.hpp>

namespace yq::tachyon {
    void JoystickAxisEvent::init_meta()
    {
        auto w = writer<JoystickAxisEvent>();
        w.description("Joystick Axis Event");
        w.property("axis", &JoystickAxisEvent::m_axis).description("Axis of motion").tag(kTag_Log).tag(kTag_Save);
        w.property("value", &JoystickAxisEvent::m_value).description("Current axis value").tag(kTag_Log).tag(kTag_Save);
        w.property("delta", &JoystickAxisEvent::m_delta).description("Change in value").tag(kTag_Log).tag(kTag_Save);
    }

    JoystickAxisEvent::JoystickAxisEvent(const Header&h, size_t _axis, float _value, float _delta) : 
        JoystickEvent(h), m_axis(_axis), m_value(_value), m_delta(_delta)
    {
    }
    
    JoystickAxisEvent::JoystickAxisEvent(const JoystickAxisEvent& cp, const Header&h) : 
        JoystickEvent(cp, h), m_axis(cp.m_axis), m_value(cp.m_value), m_delta(cp.m_delta)
    {
    }

    JoystickAxisEvent::~JoystickAxisEvent()
    {
    }

    PostCPtr    JoystickAxisEvent::clone(rebind_k, const Header&h) const 
    {
        return new JoystickAxisEvent(*this, h);
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::JoystickAxisEvent)
