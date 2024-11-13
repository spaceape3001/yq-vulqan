////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "JoystickHatEvent.hpp"
#include <yq/tachyon/post/EventInfoWriter.hpp>

namespace yq::tachyon {
    void JoystickHatEvent::init_info()
    {
        auto w = writer<JoystickHatEvent>();
        w.description("Joystick Hat Event");
        w.property("hat", &JoystickHatEvent::hat).tag(kTag_Log);
        w.property("state", &JoystickHatEvent::state).tag(kTag_Log);
    }

    JoystickHatEvent::JoystickHatEvent(Joystick j, size_t h, JoystickHatState st, const Param& p) : 
        JoystickEvent(j, p), m_hat(h), m_state(st)
    {
    }
    
    JoystickHatEvent::~JoystickHatEvent()
    {
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::JoystickHatEvent)
