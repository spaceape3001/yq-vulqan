////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/desktop/Joystick.hpp>

namespace yq::tachyon {
    class JoystickGLFW : public Joystick {
        YQ_TACHYON_DECLARE(JoystickGLFW, Joystick)
    public:
        JoystickGLFW(int, const Param&p = Param());
        ~JoystickGLFW();
        
        static void init_info();
        
        int glfw() const { return m_joystick; }
        
        virtual Execution tick(Context&) override;
        
        void    disconnecting();

    private:
        const int   m_joystick;
        bool        m_dead      = false;
    };

}
