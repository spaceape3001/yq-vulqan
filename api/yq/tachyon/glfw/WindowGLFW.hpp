////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Window.hpp>
#include <yq/tachyon/interfaces/IPosition2I.hpp>

struct GLFWwindow;

namespace yq::tachyon {
    class ViewerCreateInfo;

    class WindowGLFW : public Window, private IPosition2I {
        YQ_TACHYON_DECLARE(WindowGLFW, Window)
    public:
        WindowGLFW(const ViewerCreateInfo&, const Param&p={});
        ~WindowGLFW();
        
        static void init_info();
    private:
        GLFWwindow*     m_window = nullptr;
    };
}

