////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/preamble.hpp>
#include <tachyon/enum/ModifierKey.hpp>

#include <yq-toolbox/shape/Size2.hpp>
#include <yq-toolbox/vector/Vector2.hpp>
#include <system_error>

namespace yq::tachyon {
    class Window {
    public:
    
        // callback for non-window specific events
        struct Events;
    
        static bool rawMouseMotionSupported();
    
        static void set_events(Events*);
        static void poll_events();
    
    
        //static_assert(!is_template_enum_v<Hooks>, "Hooks violates enum constraitn");
    
        Window();
        
        //! Warning, this will THROW std::error_code if problems on creation!
        Window(const ViewerCreateInfo&);
        ~Window();
        
        GLFWwindow*         window() const { return m_window; }

        //  ------------------------------------------------
        //  GETTERS

            // returns the last recorded cursor position
        Vector2D            cursor() const { return m_cursor; }

        Size2I              framebuffer_size() const;

            //! Height of the window
        int                 height() const;

            //! TRUE if the window has standard decorations (close/buttons/frame)
        bool                is_decorated() const;
            //! TRUE if the window has input focus
        bool                is_focused() const;
            //! TRUE if window is floating (ie always-on-top)
        bool                is_floating() const;
            //! TRUE if the window is fullscreen
        bool                is_fullscreen() const;
            //! TRUE if the mouse cursor is hovering directly above us
        bool                is_hovered() const;
            //! TRUE if the window is iconified
        bool                is_iconified() const;
            //! TRUE if the window is maximized
        bool                is_maximized() const;
            //! TRUE if the window is resizable
        bool                is_resizable() const;
            //! TRUE if the window is visible
        bool                is_visible() const;

            //! Monitor (if fullscreen)
        Monitor             monitor() const;

            //! Current window position
        Vector2I            position() const;

            //! TRUE if user wants window to close
        bool                should_close() const;

            //! Viewer size
        Size2I              size() const;

        std::string_view    title() const { return m_title; }

            //! Width of the window
        int                 width() const;

        //  ------------------------------------------------
        //  MANIPULATION/SETTING
        
        //! Attention from the user
        void        cmd_attention();

        //! Sets the close flag
        void        cmd_close();
    
        //! Focus onto this window
        void        cmd_focus();

        //! Hides the window
        void        cmd_hide();
        
        //! Iconify/minimizes the window;
        void        cmd_iconify();
        
            //! Maximizes widnow
        void        cmd_maximize();

        //! Restore the window to non-icon/non-fullscreen
        void        cmd_restore();

            //! Show the window
        void        cmd_show();

            //! Sets the window position
        void        set_position(const Vector2I&);

            //! Sets the window position
        void        set_position(int x, int y);

            //! Sets window size
        void        set_size(const Size2I&);

            //! Sets window size
        void        set_size(int w, int h);
        
            //! Sets the window title
        void        set_title(std::string_view);

        bool                    zero_framebuffer() const;

    protected:
    
        void                install_hooks();
        
    
        //  NOTE... initializing w/o starting GLFW is bad mojo!
        std::error_code     init_window(const ViewerCreateInfo&);
        virtual void        kill_window();

            /*
                USER EVENT CALLBACKS.....
            */

        //! User entered a character
        virtual void        character(unsigned int) {}
        
        //! User moved the window
        virtual void        window_moved(const Vector2I&){}
        
        //! User resized the window
        virtual void        window_resized(const Size2I&) {}
        
        //! User rescaled the window DPI (moving, system change, etc)
        virtual void        window_scaled(const Vector2F&) {}
        
        //! User requested a window close
        virtual void        window_close_requested();
        
        //! Cursor (mouse) moved
        virtual void        mouse_moved(const Vector2D&) {}
        
        //! Files were dropped 
        //! \note COPY the data if it needs to be retained!
        virtual void        user_dropped(std::span<const char*>){}
        
        //! Cursor (mouse) has entered the widnow
        virtual void        mouse_entered() {}
        
        virtual void        key_pressed(int key, int scancode, ModifierKeys) {}
        virtual void        key_released(int key, int scancode, ModifierKeys) {}
        virtual void        key_repeat(int key, int scancode, ModifierKeys) {}
        
        //! Cursor (mouse) has left the window
        virtual void        mouse_left() {}
        
        virtual void        mouse_pressed(int button, const Vector2D&, ModifierKeys){}
        virtual void        mouse_released(int button, const Vector2D&, ModifierKeys){}
        
        virtual void        scroll_wheel(const Vector2D&){}
        
        //! Window needs refresh
        virtual void        window_refresh_requested() {}
        
        //! Window has gained focus
        virtual void        window_focused() {}
        
        //! Window has lost focus
        virtual void        window_unfocused() {}
        
        //! Window was minimized into icon-only
        virtual void        window_iconified() {}
        
        //! Window was restored
        virtual void        window_restored() {}
        
        //! Window was maximized
        virtual void        window_maximized() {}
        
        //! Framebuffer changed (only really valid if OpenGL)
        virtual void        window_framebuffer_resized(const Size2I&){}

    private:
        Window(const Window&) = delete;
        Window(Window&&) = delete;
        
        GLFWwindow*     m_window    = nullptr;
        std::string     m_title;
        //  Updated with every callback
        Vector2D        m_cursor    = {};
        bool            m_imgui     = false;
        bool            m_init      = false;
        ModifierKeys    m_modifiers;
        static int      g_count;
        static Events*  g_events;
        static bool     g_imgui;

        static void callback_character(GLFWwindow* window, unsigned int codepoint);
        static void callback_cursor_enter(GLFWwindow* window, int entered);
        static void callback_cursor_position(GLFWwindow* window, double xpos, double ypos);
        static void callback_drop(GLFWwindow* window, int count, const char** paths);
        static void callback_framebuffer_size(GLFWwindow* window, int width, int height);
        static void callback_joystick(int jid, int event);
        static void callback_key(GLFWwindow* window, int key, int scancode, int action, int mods);
        static void callback_monitor(GLFWmonitor* monitor, int event);
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
