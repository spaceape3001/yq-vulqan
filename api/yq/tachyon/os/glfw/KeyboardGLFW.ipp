////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/os/glfw/KeyboardGLFW.hpp>
#include <yq/tachyon/os/KeyboardMetaWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::KeyboardGLFW)

namespace yq::tachyon {
    KeyboardGLFW::KeyboardGLFW(const Param&p) : Keyboard(p)
    {
    }
    
    KeyboardGLFW::~KeyboardGLFW()
    {
    }
    
    void KeyboardGLFW::init_meta()
    {
        auto w = writer<KeyboardGLFW>();
        w.description("GLFW Keyboard");
    }
}
