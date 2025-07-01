////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/os/glfw/KeyboardGLFW.hpp>
#include <tachyon/os/KeyboardMetaWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::KeyboardGLFW)

namespace yq::tachyon {
    KeyboardGLFW::KeyboardGLFW(const Param&p) : Keyboard(p)
    {
    }
    
    KeyboardGLFW::~KeyboardGLFW()
    {
    }
    
    void KeyboardGLFW::init_info()
    {
        auto w = writer<KeyboardGLFW>();
        w.description("GLFW Keyboard");
    }
}
