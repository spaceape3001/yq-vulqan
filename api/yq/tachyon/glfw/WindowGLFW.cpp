////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowGLFW.hpp"
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/api/WindowInfoWriter.hpp>
#include <yq/tachyon/commands/WindowHideCommand.hpp>
#include <yq/tachyon/commands/WindowShowCommand.hpp>
#include <yq/tachyon/events/WindowDefocusEvent.hpp>
#include <yq/tachyon/events/WindowFocusEvent.hpp>
#include <yq/tachyon/events/WindowFrameBufferResizeEvent.hpp>
#include <yq/tachyon/events/WindowHideEvent.hpp>
#include <yq/tachyon/events/WindowIconifyEvent.hpp>
#include <yq/tachyon/events/WindowMaximizeEvent.hpp>
#include <yq/tachyon/events/WindowMoveEvent.hpp>
#include <yq/tachyon/events/WindowRestoreEvent.hpp>
#include <yq/tachyon/events/WindowResizeEvent.hpp>
#include <yq/tachyon/events/WindowShowEvent.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::WindowGLFW)

namespace yq::tachyon {

    void callback_character(GLFWwindow* win, unsigned int codepoint);
    void callback_cursor_enter(GLFWwindow* win, int entered);
    void callback_cursor_position(GLFWwindow* win, double xpos, double ypos);
    void callback_drop(GLFWwindow* win, int count, const char** paths);
    void WindowGLFW::callback_framebuffer_size(GLFWwindow* win, int width, int height)
    {
        WindowGLFW *_w  = _window(win);
        if(!_w)
            return ;
        _w->send(new WindowFrameBufferResizeEvent(_w, Size2I( width, height)));
    }
    
    void callback_key(GLFWwindow* win, int key, int scancode, int action, int mods);
    void callback_mouse_button(GLFWwindow* win, int button, int action, int mods);
    void callback_scroll(GLFWwindow* win, double xoffset, double yoffset);
    void callback_window_close(GLFWwindow* win);
    void WindowGLFW::callback_window_focus(GLFWwindow* win, int focused)
    {
        WindowGLFW *_w  = _window(win);
        if(!_w)
            return ;
        if(focused){
            _w->send(new WindowFocusEvent(_w));
        } else {
            _w->send(new WindowDefocusEvent(_w));
        }
    }
    
    void WindowGLFW::callback_window_iconify(GLFWwindow* win, int iconified)
    {
        WindowGLFW *_w  = _window(win);
        if(!_w)
            return ;
        if(iconified){
            _w->send(new WindowIconifyEvent(_w));
        } else {
            _w->send(new WindowRestoreEvent(_w));
        }
    }
    
    void WindowGLFW::callback_window_maximize(GLFWwindow* win, int maximized)
    {
        WindowGLFW *_w  = _window(win);
        if(!_w)
            return ;
        if(maximized){
            _w->send(new WindowMaximizeEvent(_w));
        } else {
            _w->send(new WindowRestoreEvent(_w));
        }
    }
    
    void WindowGLFW::callback_window_position(GLFWwindow* win, int xpos, int ypos)
    {
        WindowGLFW *_w  = _window(win);
        if(!_w)
            return ;
        _w->send(new WindowMoveEvent(_w, Vector2I(xpos, ypos)));
    }
    
    void callback_window_refresh(GLFWwindow* win);
    void callback_window_scale(GLFWwindow* win, float xscale, float yscale);
    void WindowGLFW::callback_window_size(GLFWwindow* win, int width, int height)
    {
        WindowGLFW *_w  = _window(win);
        if(!_w)
            return ;
        _w->send(new WindowResizeEvent(_w, Size2I(width, height)));
    }

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

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    WindowGLFW::WindowGLFW(DesktopGLFW* d, GLFWwindow* w, const ViewerCreateInfo & vci, const Param&p) : 
        Window(vci, p), m_desktop(d), m_window(w)
    {
        assert(w && d);
        glfwSetWindowUserPointer(w, this);
        
        glfwSetFramebufferSizeCallback(w, callback_framebuffer_size);
        glfwSetWindowFocusCallback(w, callback_window_focus);
        glfwSetWindowIconifyCallback(w, callback_window_iconify);
        glfwSetWindowMaximizeCallback(w, callback_window_maximize);
        glfwSetWindowPosCallback(w, callback_window_position);
        glfwSetWindowSizeCallback(w, callback_window_size);
    }
    
    WindowGLFW::~WindowGLFW()
    {
    }

    void    WindowGLFW::on_hide_command(const WindowHideCommand&)
    {
        if(!glfwGetWindowAttrib(m_window, GLFW_VISIBLE))
            return ;
        glfwHideWindow(m_window);
        send(new WindowHideEvent(this));
    }
    
    void    WindowGLFW::on_show_command(const WindowShowCommand&)
    {
        if(glfwGetWindowAttrib(m_window, GLFW_VISIBLE))
            return ;
        glfwShowWindow(m_window);
        send(new WindowShowEvent(this));
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

    //std::string_view    WindowGLFW::title() const
    //{
    //}
    
    //void                WindowGLFW::title(const std::string&)
    //{
    //}

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void WindowGLFW::init_info()
    {
        auto w = writer<WindowGLFW>();
        w.description("GLFW Window");
        w.interface<IPosition2I>();
        w.slot(&WindowGLFW::on_hide_command);
        w.slot(&WindowGLFW::on_show_command);
    }
}
