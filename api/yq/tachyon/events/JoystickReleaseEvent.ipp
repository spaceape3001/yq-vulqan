////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "JoystickReleaseEvent.hpp"
#include <yq/post/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

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
    
    YQ_INVOKE(JoystickReleaseEvent::init_info();)
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::JoystickReleaseEvent)
