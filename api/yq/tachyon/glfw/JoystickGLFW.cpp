////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "JoystickGLFW.hpp"
#include <yq/tachyon/api/JoystickInfoWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::JoystickGLFW)

namespace yq::tachyon {
    JoystickGLFW::JoystickGLFW(int jid, const Param&p) : Joystick(p), m_joystick(jid)
    {
    }
    
    JoystickGLFW::~JoystickGLFW()
    {
    }

    Execution JoystickGLFW::tick(Context&ctx) 
    {
        Joystick::tick(ctx);
        
        //  probe
        
        return {};
    }
    
    void JoystickGLFW::init_info()
    {
        auto w = writer<JoystickGLFW>();
        w.description("GLFW Joystick");
    }
}
