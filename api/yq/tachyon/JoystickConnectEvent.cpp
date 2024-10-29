////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "JoystickConnectEvent.hpp"
#include <yq/post/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

namespace yq::tachyon {
    void JoystickConnectEvent::init_info()
    {
        auto w = writer<JoystickConnectEvent>();
        w.description("Joystick Connection Event");
    }

    JoystickConnectEvent::JoystickConnectEvent(Joystick j, const Param& p) : JoystickEvent(j, p)
    {
    }
    
    JoystickConnectEvent::~JoystickConnectEvent()
    {
    }
    
    YQ_INVOKE(JoystickConnectEvent::init_info();)
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::JoystickConnectEvent)
