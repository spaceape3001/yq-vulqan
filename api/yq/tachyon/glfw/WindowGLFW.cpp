////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowGLFW.hpp"
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/api/WindowInfoWriter.hpp>
#include <yq/tachyon/events/WindowMoveEvent.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::WindowGLFW)

namespace yq::tachyon {

    void callback_character(GLFWwindow* window, unsigned int codepoint);
    void callback_cursor_enter(GLFWwindow* window, int entered);
    void callback_cursor_position(GLFWwindow* window, double xpos, double ypos);
    void callback_drop(GLFWwindow* window, int count, const char** paths);
    void callback_framebuffer_size(GLFWwindow* window, int width, int height);
    void callback_key(GLFWwindow* window, int key, int scancode, int action, int mods);
    void callback_mouse_button(GLFWwindow* window, int button, int action, int mods);
    void callback_scroll(GLFWwindow* window, double xoffset, double yoffset);
    void callback_window_close(GLFWwindow* window);
    void callback_window_focus(GLFWwindow* window, int focused);
    void callback_window_iconify(GLFWwindow* window, int iconified);
    void callback_window_maximize(GLFWwindow* window, int maximized);
    void WindowGLFW::callback_window_position(GLFWwindow* win, int xpos, int ypos)
    {
        WindowGLFW *_w  = _window(win);
        if(!_w)
            return ;
        _w->send(new WindowMoveEvent(_w, Vector2I(xpos, ypos)));
    }
    
    void callback_window_refresh(GLFWwindow* window);
    void callback_window_scale(GLFWwindow* window, float xscale, float yscale);
    void callback_window_size(GLFWwindow*, int, int);

    WindowGLFW*  WindowGLFW::_window(GLFWwindow*w)
    {
        return  (WindowGLFW*) glfwGetWindowUserPointer(w);
    }

    WindowGLFW*  WindowGLFW::window(ptr_t, GLFWwindow* w)
    {
        return _window(w);
    }
    
    WindowID     WindowGLFW::window(GLFWwindow* w)
    {
        WindowGLFW*p    = _window(w);
        if(!p)
            return {};
        return p->id();
    }

    WindowGLFW::WindowGLFW(DesktopGLFW* d, GLFWwindow* w, const ViewerCreateInfo & vci, const Param&p) : 
        Window(vci, p), m_desktop(d), m_window(w)
    {
        assert(w && d);
        glfwSetWindowUserPointer(w, this);
        glfwSetWindowPosCallback(w, callback_window_position);
    }
    
    WindowGLFW::~WindowGLFW()
    {
    }

    void        WindowGLFW::show() 
    {
        glfwShowWindow(m_window);
    }
    
    void        WindowGLFW::hide() 
    {
        glfwHideWindow(m_window);
    }

    Vector2I    WindowGLFW::position2i() const 
    {
        Vector2I    ret;
        glfwGetWindowPos(m_window, &ret.x, &ret.y);
        return ret;
    }
    
    Execution WindowGLFW::tick(Context&ctx) 
    {
        Window::tick(ctx);
        
        //  TODO
        
        return {};
    }

    void WindowGLFW::init_info()
    {
        auto w = writer<WindowGLFW>();
        w.description("GLFW Window");
        w.interface<IPosition2I>();
    }
}
