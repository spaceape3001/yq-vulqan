////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "JoystickDisconnectEvent.hpp"
#include <yq/post/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

namespace yq::tachyon {
    void JoystickDisconnectEvent::init_info()
    {
        auto w = writer<JoystickDisconnectEvent>();
        w.description("Joystick Disconnection Event");
    }

    JoystickDisconnectEvent::JoystickDisconnectEvent(Joystick j, const Param&p) : JoystickEvent(j,p)
    {
    }
    
    JoystickDisconnectEvent::~JoystickDisconnectEvent()
    {
    }
    
    YQ_INVOKE(JoystickDisconnectEvent::init_info();)
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::JoystickDisconnectEvent)
