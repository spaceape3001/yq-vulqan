////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "JoystickDisconnectEvent.hpp"
#include <yq/tachyon/api/EventInfoWriter.hpp>

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
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::JoystickDisconnectEvent)
