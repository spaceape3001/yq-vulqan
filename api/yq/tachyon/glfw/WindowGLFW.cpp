////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowGLFW.hpp"
#include <yq/tachyon/api/WindowInfoWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::WindowGLFW)

namespace yq::tachyon {

    WindowGLFW::WindowGLFW(const ViewerCreateInfo & vci, const Param&p)
    {
    }
    
    WindowGLFW::~WindowGLFW()
    {
    }
    
    void WindowGLFW::init_info()
    {
        auto w = writer<WindowGLFW>();
        w.description("GLFW Window");
        w.interface<IPosition2I>();
    }
}
