////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "JoystickAxis.hpp"
#include <yq/tachyon/event/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

namespace yq::tachyon {
    void JoystickAxis::init_info()
    {
        auto w = writer<JoystickAxis>();
        w.description("Joystick Axis Event");
    }

    JoystickAxis::JoystickAxis(const Param& p) : JoystickEvent(p)
    {
    }
    
    JoystickAxis::~JoystickAxis()
    {
    }
    
    YQ_INVOKE(JoystickAxis::init_info();)
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::JoystickAxis)
