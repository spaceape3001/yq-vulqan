////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "KeyboardGLFW.hpp"
#include <yq/tachyon/api/KeyboardInfoWriter.hpp>

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
