////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "JoystickEvent.hpp"

#include <yq-toolbox/basic/DelayInit.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::JoystickEvent)

namespace yq::tachyon {
    
    JoystickEventInfo::JoystickEventInfo(std::string_view zName, const InputEventInfo& base, const std::source_location& sl) :
        InputEventInfo(zName, base, sl)
    {
        set(Flag::COMMAND);
    }

    ////////////////////////////////////////////////////////////////////////////

    JoystickEvent::JoystickEvent()
    {
    }
    
    JoystickEvent::~JoystickEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    static void reg_joystick_input()
    {
        {
            auto w = writer<JoystickEvent>();
            w.description("Joystick input event base class");
        }
    }
    
    YQ_INVOKE(reg_joystick_input();)
}
