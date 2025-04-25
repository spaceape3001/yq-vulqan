////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/os/Cursor.hpp>

struct GLFWcursor;

namespace yq::tachyon {
    class CursorGLFW : public Cursor {
        YQ_TACHYON_DECLARE(CursorGLFW, Cursor)
    public:
        CursorGLFW(GLFWcursor*, const Param&p = Param());
        ~CursorGLFW();
        static void init_info();
        
        GLFWcursor* glfw() const { return m_cursor; }
        
    private:
        GLFWcursor* const m_cursor;
    };
}
