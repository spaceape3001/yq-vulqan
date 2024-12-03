////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowGLFW.hpp"
#include <yq/tachyon/api/WindowInfoWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::WindowGLFW)

namespace yq::tachyon {

    WindowGLFW::WindowGLFW(DesktopGLFW* d, GLFWwindow* w, const ViewerCreateInfo & vci, const Param&p) : 
        Window(vci, p), m_desktop(d), m_window(w)
    {
    }
    
    WindowGLFW::~WindowGLFW()
    {
    }

    Vector2I    WindowGLFW::position2i() const 
    {
        return m_position;
    }
    
    Execution WindowGLFW::tick(Context&ctx) 
    {
        Window::tick(ctx);
        
        //  TODO
        
        return {};
    }

    void WindowGLFW::init_info()
    {
        auto w = writer<WindowGLFW>();
        w.description("GLFW Window");
        w.interface<IPosition2I>();
    }
}
