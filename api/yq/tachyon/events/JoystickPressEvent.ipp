////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "JoystickPressEvent.hpp"
#include <yq/post/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

namespace yq::tachyon {
    void JoystickPressEvent::init_info()
    {
        auto w = writer<JoystickPressEvent>();
        w.description("Joystick Press Event");
        w.property("button", &JoystickPressEvent::button).tag(kTag_Log);
    }

    JoystickPressEvent::JoystickPressEvent(Joystick j, size_t btn, const Param& p) : JoystickEvent(j, p), m_button(btn)
    {
    }
    
    JoystickPressEvent::~JoystickPressEvent()
    {
    }
    
    YQ_INVOKE(JoystickPressEvent::init_info();)
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::JoystickPressEvent)
