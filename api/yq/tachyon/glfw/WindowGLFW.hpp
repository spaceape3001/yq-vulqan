////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/desktop/Window.hpp>
#include <yq/tachyon/desktop/WindowState.hpp>
#include <yq/tachyon/enum/ModifierKey.hpp>
#include <yq/tachyon/enum/MouseButton.hpp>
#include <yq/tachyon/enum/MouseMode.hpp>
#include <yq/tachyon/interfaces/IPosition2.hpp>
#include <yq/tachyon/typedef/commands.hpp>
#include <yq/tachyon/typedef/glfw.hpp>

struct GLFWwindow;

namespace yq::tachyon {
    class ViewerCreateInfo;
    class WindowDestroyCommand;

    class WindowGLFW : public Window, private IPosition2 {
        YQ_TACHYON_DECLARE(WindowGLFW, Window)
    public:
        WindowGLFW(DesktopGLFW*, GLFWwindow*, const ViewerCreateInfo&, const Param&p={});
        ~WindowGLFW();
        
        static void init_info();

        Vector2D    position() const override;

        virtual Execution tick(Context&) override;
        
        static WindowGLFW*  window(ptr_k, GLFWwindow*);
        static WindowID     window(GLFWwindow*);
        
        //std::string_view    title() const;
        //void                title(const std::string&);

        // hack for the moment
        GLFWwindow*         glfw() const { return m_window; }
        
        //! LOCAL THREAD ONLY
        Size2I              framebuffer() const;

    protected:
        void        snap(WindowSnap&) const;
        virtual PostAdvice  advise(const Post&) const override;

    private:
        enum Stage {
            Preinit,
            Running,
            Destruct
        };
    
        DesktopGLFW* const  m_desktop;
        GLFWwindow* const   m_window;
        Size2I              m_aspect    = { -1, -1 };
        Size2I              m_maxSize   = { -1, -1 };
        Size2I              m_minSize   = { -1, -1 };
        MouseMode           m_mouseMode = MouseMode::Normal;
        Stage               m_stage     = Stage::Preinit;
        
        void    on_aspect_command(const WindowAspectCommand&);
        void    on_attention_command(const WindowAttentionCommand&);
        void    on_cursor_capture_command(const WindowCursorCaptureCommand&);
        void    on_cursor_disable_command(const WindowCursorDisableCommand&);
        void    on_cursor_hide_command(const WindowCursorHideCommand&);
        void    on_cursor_normal_command(const WindowCursorNormalCommand&);
        void    on_destroy_command(const WindowDestroyCommand&);
        void    on_float_command(const WindowFloatCommand&);
        void    on_focus_command(const WindowFocusCommand&);
        void    on_hide_command(const WindowHideCommand&);
        void    on_iconify_command(const WindowIconifyCommand&);
        void    on_maximize_command(const WindowMaximizeCommand&);
        void    on_move_command(const WindowMoveCommand&);
        void    on_restore_command(const WindowRestoreCommand&);
        void    on_show_command(const WindowShowCommand&);
        void    on_size_command(const WindowSizeCommand&);
        void    on_title_command(const WindowTitleCommand&);
        void    on_unfloat_command(const WindowUnfloatCommand&);
        
        ModifierKeys        modifiers() const;
        MouseButtons        buttons() const;
        Vector2D            mouse() const;
        std::string         title() const;
        WindowFlags         flags() const;

        static WindowGLFW*  _window(GLFWwindow*);

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

