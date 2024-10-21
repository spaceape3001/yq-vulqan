////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "JoystickHat.hpp"
#include <tachyon/event/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

namespace yq::tachyon {
    void JoystickHat::init_info()
    {
        auto w = writer<JoystickHat>();
        w.description("Joystick Hat Event");
    }

    JoystickHat::JoystickHat(const Param& p) : JoystickEvent(p)
    {
    }
    
    JoystickHat::~JoystickHat()
    {
    }
    
    YQ_INVOKE(JoystickHat::init_info();)
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::JoystickHat)
