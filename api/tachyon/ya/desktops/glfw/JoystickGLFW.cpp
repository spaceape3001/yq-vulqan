////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/desktops/glfw/JoystickGLFW.hpp>
#include <yt/os/JoystickInfoWriter.hpp>
#include <ya/desktops/glfw/glfw.hpp>

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

    Execution JoystickGLFW::setup(const Context&ctx)
    {
        if(!m_init){
            glfwSetJoystickUserPointer(m_joystick, this);
            
            //  Fill out the initial state
            
            m_init = true;
        }
        return Joystick::setup(ctx);
    }
    
    Execution JoystickGLFW::teardown(const Context&ctx)
    {
        if(m_init){
            glfwSetJoystickUserPointer(m_joystick, nullptr);
            m_init  = false;
        }
        return Joystick::teardown(ctx);
    }

    Execution JoystickGLFW::tick(const Context&ctx) 
    {
        return {};
    }
    
    void JoystickGLFW::init_info()
    {
        auto w = writer<JoystickGLFW>();
        w.description("GLFW Joystick");
    }
}
