////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "DesktopGLFW.hpp"
#include "ExceptionGLFW.hpp"
#include <yq/core/ThreadId.hpp>
#include <yq/tachyon/api/Context.hpp>
#include <yq/tachyon/api/DesktopInfoWriter.hpp>
#include <yq/tachyon/glfw/ExceptionGLFW.hpp>
#include <yq/tachyon/glfw/KeyboardGLFW.hpp>
#include <yq/tachyon/glfw/LoggingGLFW.hpp>
#include <GLFW/glfw3.h>

YQ_TACHYON_IMPLEMENT(yq::tachyon::DesktopGLFW)

namespace yq::tachyon {

    namespace {
        static void    glfwLogging(int ec, const char* why)
        {
            static const auto  prior = glfwSetErrorCallback(glfwLogging);
            if(ec){
                if(!why)
                    why = "Unknown error";
                glfwWarning << "GLFW error (" << ec << "): " << why;
            }
            if(prior)
                prior(ec, why);
        }
    }


    DesktopGLFW*     DesktopGLFW::s_desktop = nullptr;

    DesktopGLFW::DesktopGLFW(const AppCreateInfo&aci, const Param& p) : Desktop(p)
    {
        if(!is_main_thread()){
            throw ExceptionGLFW("GLFW must only be used on the main thread!");
        }
        if(s_desktop){
            throw ExceptionGLFW("Only one GLFW desktop per customer!");
        }
        
        glfwLogging(0, nullptr);
        glfwInitHint(GLFW_JOYSTICK_HAT_BUTTONS, GLFW_FALSE);
        glfwInit();
        m_stage = Stage::Init;
    }
    
    DesktopGLFW::~DesktopGLFW()
    {
    }

    Execution    DesktopGLFW::_tick(Context& ctx)
    {
        glfwPollEvents();
        return {};
    }
    
    Execution    DesktopGLFW::_start(Context& ctx)
    {
        m_keyboard      = create<KeyboardGLFW>(CHILD);
    
        return {};
    }

    Execution DesktopGLFW::tick(Context& ctx)
    {
        Desktop::tick(ctx);
        switch(m_stage){
        case Stage::Uninit:
            return ERROR;
        case Stage::Init:
            return _start(ctx);
        case Stage::Running:
            return _tick(ctx);
        case Stage::Dead:
        default:
            return ERROR;
        }
    }

    void DesktopGLFW::init_info()
    {
        auto w = writer<DesktopGLFW>();
        w.description("GLFW Desktop");
        w.execution(ALWAYS);
    }
}
