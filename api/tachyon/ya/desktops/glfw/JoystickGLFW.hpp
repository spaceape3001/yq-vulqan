////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/os/Joystick.hpp>

namespace yq::tachyon {
    class JoystickGLFW : public Joystick {
        YQ_TACHYON_DECLARE(JoystickGLFW, Joystick)
    public:
        JoystickGLFW(int, const Param&p = Param());
        ~JoystickGLFW();
        
        static void init_info();
        
        int glfw() const { return m_joystick; }
        
        virtual Execution setup(const Context&);
        virtual Execution tick(const Context&);
        virtual Execution teardown(const Context&);
        
        void    disconnecting();

    private:
        const int   m_joystick;
        bool        m_init  = false;
    };

}
