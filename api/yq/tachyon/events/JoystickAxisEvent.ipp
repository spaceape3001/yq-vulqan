////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "JoystickAxisEvent.hpp"
#include <yq/post/EventInfoWriter.hpp>

namespace yq::tachyon {
    void JoystickAxisEvent::init_info()
    {
        auto w = writer<JoystickAxisEvent>();
        w.description("Joystick Axis Event");
        w.property("axis", &JoystickAxisEvent::axis).description("Axis of motion").tag(kTag_Log);
        w.property("value", &JoystickAxisEvent::value).description("Current axis value").tag(kTag_Log);
        w.property("delta", &JoystickAxisEvent::delta).description("Change in value").tag(kTag_Log);
    }

    JoystickAxisEvent::JoystickAxisEvent(Joystick j, size_t _axis, float _value, float _delta, const Param& p) : 
        JoystickEvent(j, p), m_axis(_axis), m_value(_value), m_delta(_delta)
    {
    }
    
    JoystickAxisEvent::~JoystickAxisEvent()
    {
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::JoystickAxisEvent)
