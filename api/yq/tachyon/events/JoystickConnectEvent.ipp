////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "JoystickConnectEvent.hpp"
#include <yq/tachyon/post/EventInfoWriter.hpp>

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
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::JoystickConnectEvent)
