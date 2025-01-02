////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "JoystickGLFW.hpp"
#include <yt/os/JoystickInfoWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::JoystickGLFW)

namespace yq::tachyon {
    JoystickGLFW::JoystickGLFW(int jid, const Param&p) : Joystick(p), m_joystick(jid)
    {
    }
    
    JoystickGLFW::~JoystickGLFW()
    {
    }

    void    JoystickGLFW::disconnecting()
    {
    }

    Execution JoystickGLFW::tick(Context&ctx) 
    {
        Joystick::tick(ctx);
        if(m_dead)
            return STOP;
        
        
        //  probe
        
        return {};
    }
    
    void JoystickGLFW::init_info()
    {
        auto w = writer<JoystickGLFW>();
        w.description("GLFW Joystick");
    }
}
