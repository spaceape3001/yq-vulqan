////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "JoystickEvent.hpp"

#include <tachyon/event/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::JoystickEvent)

namespace yq::tachyon {
    
    JoystickEventInfo::JoystickEventInfo(std::string_view zName, const InputEventInfo& base, const std::source_location& sl) :
        InputEventInfo(zName, base, sl)
    {
        set(Flag::JOYSTICK);
    }

    ////////////////////////////////////////////////////////////////////////////

    JoystickEvent::JoystickEvent(Joystick j) : m_joystick(j)
    {
    }
    
    JoystickEvent::~JoystickEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    static void reg_joystick_event()
    {
        {
            auto w = writer<JoystickEvent>();
            w.description("Joystick event base class");
        }
    }
    
    YQ_INVOKE(reg_joystick_event();)
}
