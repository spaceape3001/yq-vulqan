////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "JoystickPress.hpp"
#include <yq/tachyon/event/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

namespace yq::tachyon {
    void JoystickPress::init_info()
    {
        auto w = writer<JoystickPress>();
        w.description("Joystick Press Event");
    }

    JoystickPress::JoystickPress(const Param& p) : JoystickEvent(p)
    {
    }
    
    JoystickPress::~JoystickPress()
    {
    }
    
    YQ_INVOKE(JoystickPress::init_info();)
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::JoystickPress)
