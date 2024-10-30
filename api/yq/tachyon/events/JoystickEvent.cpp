////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "JoystickEvent.hpp"

#include <yq/post/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::JoystickEvent)

namespace yq::tachyon {
    
    JoystickEventInfo::JoystickEventInfo(std::string_view zName, post::EventInfo& base, const std::source_location& sl) :
        post::EventInfo(zName, base, sl)
    {
        set(Flag::JOYSTICK);
    }

    ////////////////////////////////////////////////////////////////////////////

    JoystickEvent::JoystickEvent(Joystick j, const Param& p) : post::Event(p), m_joystick(j)
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