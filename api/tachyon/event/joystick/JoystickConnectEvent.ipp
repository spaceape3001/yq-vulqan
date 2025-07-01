////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/joystick/JoystickConnectEvent.hpp>
#include <tachyon/api/EventMetaWriter.hpp>

namespace yq::tachyon {
    void JoystickConnectEvent::init_info()
    {
        auto w = writer<JoystickConnectEvent>();
        w.description("Joystick Connection Event");
    }

    JoystickConnectEvent::JoystickConnectEvent(const Header&h) : JoystickEvent(h)
    {
    }
    
    JoystickConnectEvent::JoystickConnectEvent(const JoystickConnectEvent& cp, const Header&h) : JoystickEvent(cp, h)
    {
    }

    JoystickConnectEvent::~JoystickConnectEvent()
    {
    }

    PostCPtr    JoystickConnectEvent::clone(rebind_k, const Header&h) const
    {
        return new JoystickConnectEvent(*this, h);
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::JoystickConnectEvent)
