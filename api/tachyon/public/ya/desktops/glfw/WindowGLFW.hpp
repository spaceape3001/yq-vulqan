////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/os/Window.hpp>
#include <yt/os/WindowState.hpp>
#include <yt/os/ModifierKey.hpp>
#include <yt/os/MouseButton.hpp>
#include <yt/os/MouseMode.hpp>
#include <ya/aspects/AMaxSize2.hpp>
#include <ya/aspects/AMinSize2.hpp>
#include <ya/aspects/APosition2.hpp>
#include <ya/aspects/ASize2.hpp>
#include <ya/aspects/AScale2.hpp>
#include <ya/typedef/commands.hpp>

struct GLFWwindow;

namespace yq::tachyon {
    class DesktopGLFW;
    class ViewerCreateInfo;
    class WindowDestroyCommand;
    class AttentionCommand;
    class FocusCommand;
    class HideCommand;
    class IconifyCommand;
    class MaximizeCommand;
    class RestoreCommand;
    class ShowCommand;

    class WindowGLFW : public Window, 
        public APosition², public AMaxSize², public AMinSize², public ASize²,
        public AScale²
    {
        YQ_TACHYON_DECLARE(WindowGLFW, Window)
    public:
        WindowGLFW(DesktopGLFW*, GLFWwindow*, const ViewerCreateInfo&, const Param&p={});
        ~WindowGLFW();
        
        static void init_info();

        static WindowGLFW*  window(ptr_k, GLFWwindow*);
        static WindowID     window(GLFWwindow*);
 
 
        virtual Execution tick(Context&) override;
        
        
        //std::string_view    title() const;
        //void                title(const std::string&);

        // hack for the moment
        GLFWwindow*         glfw() const { return m_window; }
        
        //! LOCAL THREAD ONLY
        Size2I              framebuffer(read_k) const;
        
        using AMaxSize²::max_size;
        virtual void    max_size(set_k, const Size2D&) override;

        using AMinSize²::min_size;
        virtual void    min_size(set_k, const Size2D&) override;
        
        using APosition²::position;
        Vector2D        position(read_k) const;
        virtual void    position(set_k, const Vector2D&) override;

        using AScale²::scale;
        bool            scale(addable_k) const override { return false; }
        bool            scale(multipliable_k) const override { return false; }
        Vector2D        scale(read_k) const;
        // This is OS driven
        virtual void    scale(set_k, const Vector2D&);
        bool            scale(settable_k) const override { return false; }


        using ASize²::size;
        Size2D          size(read_k) const;
        virtual void    size(set_k, const Size2D&) override;


    protected:
        void        snap(WindowSnap&) const;
        virtual PostAdvice  advise(const Post&) const override;
        
        using Tachyon::send;
        using Tachyon::mark;

    private:
        enum Stage {
            Preinit,
            Running,
            Destruct
        };
    
        DesktopGLFW* const  m_desktop;
        GLFWwindow* const   m_window;
        Size2I              m_aspect    = { -1, -1 };
        Size2I              m_maxSize   = { -1, -1 };   // used to store the old values
        Size2I              m_minSize   = { -1, -1 };   // used to store the old values
        MouseMode           m_mouseMode = MouseMode::Normal;
        Stage               m_stage     = Stage::Preinit;
        
        
        void    on_aspect_command(const WindowAspectCommand&);
        void    on_attention_command(const AttentionCommand&);
        void    on_cursor_capture_command(const WindowCursorCaptureCommand&);
        void    on_cursor_disable_command(const WindowCursorDisableCommand&);
        void    on_cursor_hide_command(const WindowCursorHideCommand&);
        void    on_cursor_normal_command(const WindowCursorNormalCommand&);
        void    on_destroy_command(const WindowDestroyCommand&);
        void    on_float_command(const WindowFloatCommand&);
        void    on_focus_command(const FocusCommand&);
        void    on_hide_command(const HideCommand&);
        void    on_iconify_command(const IconifyCommand&);
        void    on_maximize_command(const MaximizeCommand&);
        void    on_restore_command(const RestoreCommand&);
        void    on_show_command(const ShowCommand&);
        void    on_title_command(const WindowTitleCommand&);
        void    on_unfloat_command(const WindowUnfloatCommand&);
        
        ModifierKeys        modifiers(read_k) const;
        MouseButtons        buttons(read_k) const;
        Vector2D            mouse(read_k) const;
        std::string         title(read_k) const;
        WindowFlags         flags(read_k) const;

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

