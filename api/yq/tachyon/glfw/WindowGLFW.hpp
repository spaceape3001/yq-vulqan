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

        Vector2I    position2i() const override;

        virtual Execution tick(Context&) override;

    private:
        GLFWwindow*     m_window = nullptr;
        
        Vector2I        m_position;

        static void callback_character(GLFWwindow* window, unsigned int codepoint);
        static void callback_cursor_enter(GLFWwindow* window, int entered);
        static void callback_cursor_position(GLFWwindow* window, double xpos, double ypos);
        static void callback_drop(GLFWwindow* window, int count, const char** paths);
        static void callback_framebuffer_size(GLFWwindow* window, int width, int height);
        static void callback_key(GLFWwindow* window, int key, int scancode, int action, int mods);
        static void callback_mouse_button(GLFWwindow* window, int button, int action, int mods);
        static void callback_scroll(GLFWwindow* window, double xoffset, double yoffset);
        static void callback_window_close(GLFWwindow* window);
        static void callback_window_focus(GLFWwindow* window, int focused);
        static void callback_window_iconify(GLFWwindow* window, int iconified);
        static void callback_window_maximize(GLFWwindow* window, int maximized);
        static void callback_window_position(GLFWwindow* window, int xpos, int ypos);
        static void callback_window_refresh(GLFWwindow* window);
        static void callback_window_scale(GLFWwindow* window, float xscale, float yscale);
        static void callback_window_size(GLFWwindow*, int, int);
    };
}

