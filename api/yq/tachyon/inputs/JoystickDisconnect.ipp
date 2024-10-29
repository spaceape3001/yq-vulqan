////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "JoystickDisconnect.hpp"
#include <yq/tachyon/event/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

namespace yq::tachyon {
    void JoystickDisconnect::init_info()
    {
        auto w = writer<JoystickDisconnect>();
        w.description("Joystick Disconnection Event");
    }

    JoystickDisconnect::JoystickDisconnect(const Param&p) : JoystickEvent(p)
    {
    }
    
    JoystickDisconnect::~JoystickDisconnect()
    {
    }
    
    YQ_INVOKE(JoystickDisconnect::init_info();)
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::JoystickDisconnect)
