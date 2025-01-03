////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/ID.hpp>
#include <yt/typedef/joystick.hpp>

namespace yq::tachyon {
    class Joystick;

    //! Utiltity to bind a viewer to the whatever...
    class JoystickBind {
    public:
        JoystickID    joystick() const { return m_joystick; }
        
    protected:
        JoystickBind(JoystickID v) : m_joystick(v) {}
        JoystickBind(const Joystick* v);
        virtual ~JoystickBind() {}
        
        JoystickID const m_joystick;
    };
}
