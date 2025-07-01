////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/joystick/JoystickPressEvent.hpp>
#include <tachyon/api/EventMetaWriter.hpp>

namespace yq::tachyon {
    void JoystickPressEvent::init_meta()
    {
        auto w = writer<JoystickPressEvent>();
        w.description("Joystick Press Event");
        w.property("button", &JoystickPressEvent::m_button).tag(kTag_Log).tag(kTag_Save);
    }

    JoystickPressEvent::JoystickPressEvent(const Header&h, size_t btn) : JoystickEvent(h), m_button(btn)
    {
    }
    
    JoystickPressEvent::JoystickPressEvent(const JoystickPressEvent& cp, const Header&h) : 
        JoystickEvent(cp, h), m_button(cp.m_button)
    {
    }

    JoystickPressEvent::~JoystickPressEvent()
    {
    }

    PostCPtr    JoystickPressEvent::clone(rebind_k, const Header&h) const
    {
        return new JoystickPressEvent(*this, h);
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::JoystickPressEvent)
