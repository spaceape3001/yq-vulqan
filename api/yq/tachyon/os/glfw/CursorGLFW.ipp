////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/os/glfw/CursorGLFW.hpp>
#include <yq/tachyon/os/CursorMetaWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::CursorGLFW)

namespace yq::tachyon {
    CursorGLFW::CursorGLFW(GLFWcursor* c, const Param&p) : Cursor(p), m_cursor(c)
    {
        assert(c && "CURSOR POINTER MUST BE VALID!");
    }
    
    CursorGLFW::~CursorGLFW()
    {
    }
    
    void CursorGLFW::init_meta()
    {
        auto w = writer<CursorGLFW>();
        w.description("GLFW Cursor");
    }
}
