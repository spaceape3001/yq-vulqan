////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "DesktopGLFW.hpp"
#include "GLFWException.hpp"
#include <yq/tachyon/api/Context.hpp>
#include <yq/tachyon/api/DesktopInfoWriter.hpp>
#include <GLFW/glfw3.h>

YQ_TACHYON_IMPLEMENT(yq::tachyon::DesktopGLFW)

namespace yq::tachyon {

    DesktopGLFW*     DesktopGLFW::s_desktop = nullptr;

    DesktopGLFW::DesktopGLFW(const AppCreateInfo&aci, const Param& p) : Desktop(p)
    {
    }
    
    DesktopGLFW::~DesktopGLFW()
    {
    }

    Execution DesktopGLFW::tick(Context&ctx)
    {
        Desktop::tick(ctx);
        switch(m_stage){
        case Stage::Uninit:
            return PAUSE;
        case Stage::Running:
            break;
        case Stage::Dead:
        default:
            return ERROR;
        }
        
        glfwPollEvents();
        //  others are part of the thread....
        return {};
    }

    void DesktopGLFW::init_info()
    {
        auto w = writer<DesktopGLFW>();
        w.description("GLFW Desktop");
        w.execution(ALWAYS);
    }
}
