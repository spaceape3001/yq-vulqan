////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/os/glfw/CursorGLFW.hpp>
#include <yt/os/CursorInfoWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::CursorGLFW)

namespace yq::tachyon {
    CursorGLFW::CursorGLFW(GLFWcursor* c, const Param&p) : Cursor(p), m_cursor(c)
    {
        assert(c && "CURSOR POINTER MUST BE VALID!");
    }
    
    CursorGLFW::~CursorGLFW()
    {
    }
    
    void CursorGLFW::init_info()
    {
        auto w = writer<CursorGLFW>();
        w.description("GLFW Cursor");
    }
}
