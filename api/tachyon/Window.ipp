////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/Joystick.hpp>
#include <tachyon/Monitor.hpp>
#include <tachyon/Window.hpp>
#include <tachyon/WindowEvents.hpp>
#include <tachyon/imgui/ImGuiGLFW.hpp>
#include <tachyon/imgui/ImGuiVulkan.hpp>
#include <tachyon/ViewerCreateInfo.hpp>
#include <tachyon/TachyonLog.hpp>
#include <basic/ErrorDB.hpp>
#include <basic/TextUtils.hpp>
#include <GLFW/glfw3.h>
#include <tachyon/imgui/MyImGui.hpp>


namespace yq::tachyon {

    int                 Window::g_count = 0;
    Window::Events*     Window::g_events = nullptr;
    bool                Window::g_imgui = false;
    
    bool Window::rawMouseMotionSupported()
    {
        return glfwRawMouseMotionSupported() == GLFW_TRUE;
    }

    void Window::set_events(Events* i)
    {
        if(g_events) 
            delete g_events;
        g_events     = i;
    }

    void Window::poll_events()
    {
        glfwPollEvents();
    }

    //  ------------------------------------------------

    void Window::callback_character(GLFWwindow* window, unsigned int codepoint)
    {
        if(g_imgui)
            ImGui_ImplGlfw_CharCallback(window, codepoint);

        Window*w    = (Window*) glfwGetWindowUserPointer(window);
        if(w)
            w->character(codepoint);
    }
    
    void Window::callback_cursor_enter(GLFWwindow* window, int entered)
    {
        if(g_imgui)
            ImGui_ImplGlfw_CursorEnterCallback(window, entered);
            
        Window* w   = (Window*) glfwGetWindowUserPointer(window);
        if(w){

            switch(entered){
            case GLFW_TRUE:
                w->mouse_entered();
                break;
            case GLFW_FALSE:
                w -> mouse_left();
                break;
            }
        }
    }
    
    void Window::callback_cursor_position(GLFWwindow* window, double xpos, double ypos)
    {
        if(g_imgui)
            ImGui_ImplGlfw_CursorPosCallback(window, xpos, ypos);
            
        Window* w   = (Window*) glfwGetWindowUserPointer(window);
        if(w){
            w->m_cursor    = Vector2D(xpos, ypos);
            w->mouse_moved(w->m_cursor);
        }
    }
    
    void Window::callback_drop(GLFWwindow* window, int count, const char** paths)
    {
        Window* w   = (Window*) glfwGetWindowUserPointer(window);
        if(w)
            w->user_dropped( std::span<const char*>(paths, count));
    }
    
    void Window::callback_framebuffer_size(GLFWwindow* window, int width, int height)
    {

        Window* w   = (Window*) glfwGetWindowUserPointer(window);
        if(w)
            w -> window_framebuffer_resized(Size2I(width, height));
    }

    void Window::callback_joystick(int jid, int event)
    {
        if(g_events){
            switch(event){
            case GLFW_CONNECTED:
                g_events -> connected(Joystick(jid));
                break;
            case GLFW_DISCONNECTED:
                g_events -> disconnected(Joystick(jid));
                break;
            }
        }
    }
    
    void Window::callback_key(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        if(g_imgui)
            ImGui_ImplGlfw_KeyCallback(window, key, scancode, action, mods);

        Window* w   = (Window*) glfwGetWindowUserPointer(window);
        if(w){
            switch(action){
            case GLFW_PRESS:
                w->key_pressed(key, scancode, ModifierKeys((uint8_t) mods));
                break;
            case GLFW_RELEASE:
                w->key_released(key, scancode, ModifierKeys((uint8_t) mods));
                break;
            case GLFW_REPEAT:
                w->key_repeat(key, scancode, ModifierKeys((uint8_t) mods));
                break;
            }
        }
    }
    
    void Window::callback_monitor(GLFWmonitor* mon, int event)
    {
        if(g_imgui)
            ImGui_ImplGlfw_MonitorCallback(mon, event);
        if(g_events){
            switch(event){
            case GLFW_CONNECTED:
                g_events -> connected(Monitor(mon));
                break;
            case GLFW_DISCONNECTED:
                g_events -> disconnected(Monitor(mon));
                break;
            }
        }
    }
    
    void Window::callback_mouse_button(GLFWwindow* window, int button, int action, int mods)
    {
        if(g_imgui)
            ImGui_ImplGlfw_MouseButtonCallback(window, button, action, mods);

        Window* w   = (Window*) glfwGetWindowUserPointer(window);
        if(w){
            switch(action){
            case GLFW_PRESS:
                w->mouse_pressed(button, w->m_cursor, ModifierKeys((uint8_t) mods));
                break;
            case GLFW_RELEASE:
                w->mouse_released(button, w->m_cursor, ModifierKeys((uint8_t) mods));
                break;
            }
        }
    }
    
    void Window::callback_scroll(GLFWwindow* window, double xoffset, double yoffset)
    {
        if(g_imgui)
            ImGui_ImplGlfw_ScrollCallback(window, xoffset, yoffset);

        Window* w   = (Window*) glfwGetWindowUserPointer(window);
        if(w)
            w -> scroll_wheel(Vector2D(xoffset, yoffset));
    }
    
    void Window::callback_window_close(GLFWwindow* window)
    {
        Window* w   = (Window*) glfwGetWindowUserPointer(window);
        if(w) {
            w->window_close_requested();
        } else {
            glfwSetWindowShouldClose(window, GLFW_TRUE);
        }
    }
    
    void Window::callback_window_focus(GLFWwindow* window, int focused)
    {
        if(g_imgui)
            ImGui_ImplGlfw_WindowFocusCallback(window, focused);
        Window* w   = (Window*) glfwGetWindowUserPointer(window);
        if(w){
            switch(focused){
            case GLFW_TRUE:
                w -> window_focused();
                break;
            case GLFW_FALSE:
                w -> window_unfocused();
                break;
            }
        }
    }
    
    void Window::callback_window_iconify(GLFWwindow* window, int iconified)
    {
        Window* w   = (Window*) glfwGetWindowUserPointer(window);
        if(w){
            switch(iconified){
            case GLFW_TRUE:
                w -> window_iconified();
                break;
            case GLFW_FALSE:
                w -> window_restored();
                break;
            }
        }
    }
    
    void Window::callback_window_maximize(GLFWwindow* window, int maximized)
    {
        Window* w   = (Window*) glfwGetWindowUserPointer(window);
        if(w){
            switch(maximized){
            case GLFW_TRUE:
                w -> window_maximized();
                break;
            case GLFW_FALSE:
                w -> window_restored();
                break;
            }
        }
    }
    
    void Window::callback_window_position(GLFWwindow* window, int xpos, int ypos)
    {
        Window* w   = (Window*) glfwGetWindowUserPointer(window);
        if(w)
            w->window_moved(Vector2I(xpos, ypos));
    }
    
    void Window::callback_window_refresh(GLFWwindow* window)
    {
        Window* w   = (Window*) glfwGetWindowUserPointer(window);
        if(w)
            w->window_refresh_requested();
    }
    
    void Window::callback_window_scale(GLFWwindow* window, float xscale, float yscale)
    {
        Window* w   = (Window*) glfwGetWindowUserPointer(window);
        if(w)
            w->window_scaled(Vector2F(xscale, yscale));
    }
    
    void Window::callback_window_size(GLFWwindow* window, int width, int height)
    {
        Window* w   = (Window*) glfwGetWindowUserPointer(window);
        if(w)
            w->window_resized(Size2I(width, height));
    }

    //  ------------------------------------------------

    Window::Window()
    {
        ++g_count;
    }
    
    Window::Window(const ViewerCreateInfo&vci)  : Window()
    {
        std::error_code ec = init_window(vci);
        if(ec)
            throw ec;
    }

    Window::~Window()
    {
        --g_count;
        kill_window();
    }
            
    //  ------------------------------------------------
    //  CREATION/INITIALIZATION

    std::error_code Window::init_window(const ViewerCreateInfo&vci)
    {
        if(m_init)
            return std::error_code();
        
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_FLOATING, vci.floating ? GLFW_TRUE : GLFW_FALSE);
        glfwWindowHint(GLFW_DECORATED, vci.decorated ? GLFW_TRUE : GLFW_FALSE);
        glfwWindowHint(GLFW_RESIZABLE, vci.resizable ? GLFW_TRUE : GLFW_FALSE);
        
        int wx      = std::max(1,vci.size.width());
        int wy      = std::max(1,vci.size.height());

        m_title     = vci.title;
        m_window    = glfwCreateWindow(wx, wy, m_title.c_str(), vci.monitor.monitor(), nullptr);
        if(!m_window){
            const char* description = nullptr;
            glfwGetError(&description);
            if(description)
                tachyonCritical << "GLFW Unable to create window.  " << description;
            return create_error<"Unable to create GLFW window">();
        }
        
        if(vci.imgui)
            g_imgui = true;

        m_init      = true;
        return std::error_code();
    }
    
    void            Window::install_hooks()
    {
        static bool s_init     = false;
        if(!s_init){
            glfwSetJoystickCallback( callback_joystick );
            glfwSetMonitorCallback( callback_monitor );
            s_init  = true;
        }

        glfwSetWindowUserPointer(m_window, this);

        glfwSetCharCallback(m_window, callback_character);
        glfwSetCursorEnterCallback(m_window, callback_cursor_enter);
        glfwSetCursorPosCallback(m_window, callback_cursor_position);
        glfwSetDropCallback(m_window, callback_drop);
        glfwSetFramebufferSizeCallback(m_window, callback_framebuffer_size);
        glfwSetKeyCallback(m_window, callback_key);
        glfwSetMouseButtonCallback(m_window, callback_mouse_button);
        glfwSetScrollCallback(m_window, callback_scroll);
        glfwSetWindowCloseCallback(m_window, callback_window_close);
        glfwSetWindowContentScaleCallback(m_window, callback_window_scale);
        glfwSetWindowFocusCallback(m_window, callback_window_focus);
        glfwSetWindowIconifyCallback(m_window, callback_window_iconify);
        glfwSetWindowMaximizeCallback(m_window, callback_window_maximize);
        glfwSetWindowPosCallback(m_window, callback_window_position);
        glfwSetWindowRefreshCallback(m_window, callback_window_refresh);
        glfwSetWindowSizeCallback(m_window, callback_window_size);
    }

    void            Window::kill_window()
    {
        if(!m_init)
            return;

        if(m_window){
            glfwDestroyWindow(m_window);
            m_window    = nullptr;
        }
    }

    //  ------------------------------------------------
    //  MANIPULATION

    void        Window::cmd_attention()
    {
        if(m_window)
            glfwRequestWindowAttention(m_window);
    }

    void        Window::cmd_close()
    {
        if(m_window)
            glfwSetWindowShouldClose(m_window, GLFW_TRUE);
    }
    
    void        Window::cmd_focus()
    {
        if(m_window)
            glfwFocusWindow(m_window);
    }

    void        Window::cmd_hide()
    {
        if(m_window)
            glfwHideWindow(m_window);
    }
    
    void        Window::cmd_iconify()
    {
        if(m_window)
            glfwIconifyWindow(m_window);
    }
    
    void        Window::cmd_maximize()
    {
        if(m_window)
            glfwMaximizeWindow(m_window);
    }

    void        Window::cmd_restore()
    {
        if(m_window)
            glfwRestoreWindow(m_window);
    }
    
    void        Window::cmd_show()
    {
        if(m_window)
            glfwShowWindow(m_window);
    }

    void        Window::window_close_requested()
    {
        cmd_close();
    }
    
    void        Window::set_position(int x, int y)
    {
        if(m_window){
            glfwSetWindowPos(m_window, x, y);
        }
    }

    void        Window::set_size(const Size2I& sz)
    {
        set_size(sz.x, sz.y);
    }

    void        Window::set_size(int w, int h)
    {
        if(m_window){
            glfwSetWindowSize(m_window, std::max(1, w), std::max(1, h));
        }
    }
    
    void        Window::set_position(const Vector2I& pos)
    {
        set_position(pos.x, pos.y);
    }

    void        Window::set_title(std::string_view txt)
    {
        if(m_window){
            m_title = std::string(txt);
            glfwSetWindowTitle(m_window, m_title.c_str());
        }
    }

    //  ------------------------------------------------
    //  GETTER/INFORMATION

    Size2I  Window::framebuffer_size() const
    {
        int width = 0, height = 0;
        glfwGetFramebufferSize(m_window, &width, &height);
        return Size2I(width, height);
    }
    
    int  Window::height() const
    {
        if(!m_window)
            return 0;
    
        int ret;
        glfwGetWindowSize(m_window, nullptr, &ret);
        return ret;
    }

    bool        Window::is_decorated() const
    {
        if(!m_window)
            return false;
        return glfwGetWindowAttrib(m_window, GLFW_DECORATED) != 0;
    }
    
    bool        Window::is_focused() const
    {
        if(!m_window)
            return false;
        return glfwGetWindowAttrib(m_window, GLFW_FOCUSED ) != 0;
    }
    
    bool        Window::is_floating() const
    {
        if(!m_window)
            return false;
        return glfwGetWindowAttrib(m_window, GLFW_FLOATING) != 0;
    }
    
    bool        Window::is_fullscreen() const
    {
        if(!m_window)
            return false;
        return glfwGetWindowMonitor(m_window) != nullptr;
    }
    
    bool        Window::is_hovered() const
    {
        if(!m_window)
            return false;
        return glfwGetWindowAttrib(m_window, GLFW_HOVERED) != 0;
    }
    
    bool        Window::is_iconified() const
    {
        if(!m_window)
            return false;
        return glfwGetWindowAttrib(m_window, GLFW_ICONIFIED) != 0;
    }

    bool        Window::is_maximized() const
    {
        if(!m_window)
            return false;
        return glfwGetWindowAttrib(m_window, GLFW_MAXIMIZED) != 0;
    }
    
    bool        Window::is_resizable() const
    {
        if(!m_window)
            return false;
        return glfwGetWindowAttrib(m_window, GLFW_RESIZABLE) != 0;
    }
    
    bool        Window::is_visible() const
    {
        if(!m_window)
            return false;
        return glfwGetWindowAttrib(m_window, GLFW_VISIBLE) != 0;
    }

    Monitor     Window::monitor() const
    {
        if(m_window)
            return Monitor(glfwGetWindowMonitor(m_window));
        return Monitor();
    }

    Vector2I    Window::position() const
    {
        if(!m_window)
            return {};
        Vector2I   ret;
        glfwGetWindowPos(m_window, &ret.x, &ret.y);
        return ret;
    }
    
    bool        Window::should_close() const
    {
        if(!m_window) 
            return true;
        return glfwWindowShouldClose(m_window);
    }

    Size2I      Window::size() const
    {
        if(!m_window)
            return {};
        Size2I  ret;
        glfwGetWindowSize(m_window, &ret.x, &ret.y);
        return ret;
    }
    
    int  Window::width() const
    {
        if(!m_window)
            return 0;
    
        int ret;
        glfwGetWindowSize(m_window, &ret, nullptr);
        return ret;
    }

    bool Window::zero_framebuffer() const
    {
        Size2I sz  = framebuffer_size();
        return (sz.x <= 0) || (sz.y <= 0);
    }
}
