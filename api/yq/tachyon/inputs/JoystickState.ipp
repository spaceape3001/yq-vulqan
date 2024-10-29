////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "JoystickState.hpp"
#include <yq/tachyon/event/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

namespace yq::tachyon {
    void JoystickState::init_info()
    {
        auto w = writer<JoystickState>();
        w.description("Joystick State Event");
    }

    JoystickState::JoystickState(const Param& p) : JoystickEvent(p)
    {
    }
    
    JoystickState::~JoystickState()
    {
    }
    
    YQ_INVOKE(JoystickState::init_info();)
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::JoystickState)
