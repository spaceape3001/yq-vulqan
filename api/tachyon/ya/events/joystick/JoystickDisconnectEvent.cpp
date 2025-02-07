////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/events/joystick/JoystickDisconnectEvent.hpp>
#include <yt/msg/EventInfoWriter.hpp>

namespace yq::tachyon {
    void JoystickDisconnectEvent::init_info()
    {
        auto w = writer<JoystickDisconnectEvent>();
        w.description("Joystick Disconnection Event");
    }

    JoystickDisconnectEvent::JoystickDisconnectEvent(const Header&h) : JoystickEvent(h)
    {
    }
    
    JoystickDisconnectEvent::JoystickDisconnectEvent(const JoystickDisconnectEvent& cp, const Header&h) : JoystickEvent(cp, h)
    {
    }

    JoystickDisconnectEvent::~JoystickDisconnectEvent()
    {
    }

    PostCPtr    JoystickDisconnectEvent::clone(rebind_k, const Header& h) const 
    {
        return new JoystickDisconnectEvent(*this, h);
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::JoystickDisconnectEvent)
