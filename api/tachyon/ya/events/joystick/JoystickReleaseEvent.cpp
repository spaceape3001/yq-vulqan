////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/events/joystick/JoystickReleaseEvent.hpp>
#include <yt/msg/EventInfoWriter.hpp>

namespace yq::tachyon {
    void JoystickReleaseEvent::init_info()
    {
        auto w = writer<JoystickReleaseEvent>();
        w.description("Joystick Release Event");
        w.property("button", &JoystickReleaseEvent::m_button).tag(kTag_Log).tag(kTag_Save);
    }

    JoystickReleaseEvent::JoystickReleaseEvent(const Header& h, size_t btn) : 
        JoystickEvent(h), m_button(btn)
    {
    }
    
    JoystickReleaseEvent::JoystickReleaseEvent(const JoystickReleaseEvent& cp, const Header& h) : 
        JoystickEvent(cp, h), m_button(cp.m_button)
    {
    }

    JoystickReleaseEvent::~JoystickReleaseEvent()
    {
    }

    PostCPtr    JoystickReleaseEvent::clone(rebind_k, const Header&h) const 
    {
        return new JoystickReleaseEvent(*this, h);
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::JoystickReleaseEvent)
