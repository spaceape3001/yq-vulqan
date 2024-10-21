////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "JoystickConnect.hpp"
#include <tachyon/event/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

namespace yq::tachyon {
    void JoystickConnect::init_info()
    {
        auto w = writer<JoystickConnect>();
        w.description("Joystick Connection Event");
    }

    JoystickConnect::JoystickConnect(const Param& p) : JoystickEvent(p)
    {
    }
    
    JoystickConnect::~JoystickConnect()
    {
    }
    
    YQ_INVOKE(JoystickConnect::init_info();)
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::JoystickConnect)
