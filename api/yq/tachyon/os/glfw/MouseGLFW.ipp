////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/os/glfw/MouseGLFW.hpp>
#include <yq/tachyon/os/MouseMetaWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::MouseGLFW)

namespace yq::tachyon {
    MouseGLFW::MouseGLFW(const Param&p) : Mouse(p)
    {
    }
    
    MouseGLFW::~MouseGLFW()
    {
    }
    
    void MouseGLFW::init_meta()
    {
        auto w = writer<MouseGLFW>();
        w.description("GLFW Mouse");
    }
}
