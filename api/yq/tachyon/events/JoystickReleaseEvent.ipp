////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "JoystickReleaseEvent.hpp"
#include <yq/tachyon/api/EventInfoWriter.hpp>

namespace yq::tachyon {
    void JoystickReleaseEvent::init_info()
    {
        auto w = writer<JoystickReleaseEvent>();
        w.description("Joystick Release Event");
        w.property("button", &JoystickReleaseEvent::button).tag(kTag_Log);
    }

    JoystickReleaseEvent::JoystickReleaseEvent(Joystick j, size_t btn, const Param& p) : 
        JoystickEvent(j, p), m_button(btn)
    {
    }
    
    JoystickReleaseEvent::~JoystickReleaseEvent()
    {
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::JoystickReleaseEvent)
