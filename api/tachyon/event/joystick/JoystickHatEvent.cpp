////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/joystick/JoystickHatEvent.hpp>
#include <tachyon/api/EventInfoWriter.hpp>

namespace yq::tachyon {
    void JoystickHatEvent::init_info()
    {
        auto w = writer<JoystickHatEvent>();
        w.description("Joystick Hat Event");
        w.property("hat", &JoystickHatEvent::m_hat).tag(kTag_Log).tag(kTag_Save);
        w.property("state", &JoystickHatEvent::m_state).tag(kTag_Log).tag(kTag_Save);
    }

    JoystickHatEvent::JoystickHatEvent(const Header&h, size_t _hat, HatState st) : 
        JoystickEvent(h), m_hat(_hat), m_state(st)
    {
    }
    
    JoystickHatEvent::JoystickHatEvent(const JoystickHatEvent& cp, const Header&h) : 
        JoystickEvent(cp, h), m_hat(cp.m_hat), m_state(cp.m_state)
    {
    }
    

    JoystickHatEvent::~JoystickHatEvent()
    {
    }

    PostCPtr    JoystickHatEvent::clone(rebind_k, const Header&h) const
    {
        return new JoystickHatEvent(*this, h);
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::JoystickHatEvent)
