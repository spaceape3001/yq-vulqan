////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/os/glfw/MouseGLFW.hpp>
#include <tachyon/os/MouseInfoWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::MouseGLFW)

namespace yq::tachyon {
    MouseGLFW::MouseGLFW(const Param&p) : Mouse(p)
    {
    }
    
    MouseGLFW::~MouseGLFW()
    {
    }
    
    void MouseGLFW::init_info()
    {
        auto w = writer<MouseGLFW>();
        w.description("GLFW Mouse");
    }
}
