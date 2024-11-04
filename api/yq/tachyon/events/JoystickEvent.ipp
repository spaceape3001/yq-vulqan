////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "JoystickEvent.hpp"

#include <yq/post/EventInfoWriter.hpp>

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

    void JoystickEvent::init_info()
    {
        auto w = writer<JoystickEvent>();
        w.description("Joystick event base class");
        w.property("jid", &JoystickEvent::joystick_id).tag(kTag_Log);
    }
}
