////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/event/joystick/JoystickDisconnectEvent.hpp>
#include <yq/tachyon/api/EventMetaWriter.hpp>

namespace yq::tachyon {
    void JoystickDisconnectEvent::init_meta()
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
