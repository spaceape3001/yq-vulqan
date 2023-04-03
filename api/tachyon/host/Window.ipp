////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/host/Monitor.hpp>
#include <tachyon/host/Window.hpp>
#include <tachyon/ViewerCreateInfo.hpp>
#include <basic/ErrorDB.hpp>
#include <GLFW/glfw3.h>

namespace yq {
    namespace tachyon {
        
        bool Window::rawMouseMotionSupported()
        {
            return glfwRawMouseMotionSupported() == GLFW_TRUE;
        }

        //  ------------------------------------------------

        //  ------------------------------------------------

        Window::Window()
        {
        }
        
        Window::Window(const ViewerCreateInfo&vci)
        {
            std::error_code ec = init_window(vci);
            if(ec)
                throw ec;
        }

        Window::~Window()
        {
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
            if(!m_window)
                return create_error<"Unable to create GLFW window">();

            glfwSetWindowUserPointer(m_window, this);
            m_init      = true;
            return std::error_code();
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
    }
}

