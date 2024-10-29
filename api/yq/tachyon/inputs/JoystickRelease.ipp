////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "JoystickRelease.hpp"
#include <tachyon/event/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

namespace yq::tachyon {
    void JoystickRelease::init_info()
    {
        auto w = writer<JoystickRelease>();
        w.description("Joystick Release Event");
    }

    JoystickRelease::JoystickRelease(const Param& p) : JoystickEvent(p)
    {
    }
    
    JoystickRelease::~JoystickRelease()
    {
    }
    
    YQ_INVOKE(JoystickRelease::init_info();)
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::JoystickRelease)
