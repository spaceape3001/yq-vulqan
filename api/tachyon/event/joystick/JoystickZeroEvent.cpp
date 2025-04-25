////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/joystick/JoystickZeroEvent.hpp>
#include <tachyon/api/EventInfoWriter.hpp>

namespace yq::tachyon {
    void JoystickZeroEvent::init_info()
    {
        auto w = writer<JoystickZeroEvent>();
        w.description("Joystick Zeroion Event");
    }

    JoystickZeroEvent::JoystickZeroEvent(const Header&h) : JoystickEvent(h)
    {
    }
    
    JoystickZeroEvent::JoystickZeroEvent(const JoystickZeroEvent& cp, const Header&h) : JoystickEvent(cp, h)
    {
    }

    JoystickZeroEvent::~JoystickZeroEvent()
    {
    }

    PostCPtr    JoystickZeroEvent::clone(rebind_k, const Header&h) const
    {
        return new JoystickZeroEvent(*this, h);
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::JoystickZeroEvent)
