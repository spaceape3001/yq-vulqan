////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/Manager.hpp>
#include <yq/tachyon/enum/ModifierKey.hpp>
#include <yq/tachyon/enum/MouseButton.hpp>
#include <yt/typedef/viewer.hpp>
#include <yq/typedef/size2.hpp>
#include <yq/typedef/vector2.hpp>

struct GLFWwindow;
struct GLFWmonitor;

namespace yq::tachyon {
    class Viewer;
    class Joystick;
    class Application;
    
    struct ViewerState;
    struct ViewerCreateInfo;

    class WindowAspectCommand;
    class WindowAttentionCommand;
    class WindowCursorCaptureCommand;
    class WindowCursorDisableCommand;
    class WindowCursorHideCommand;
    class WindowCursorNormalCommand;
    class WindowDestroyCommand;
    class WindowFloatCommand;
    class WindowFocusCommand;
    class WindowHideCommand;
    class WindowIconifyCommand;
    class WindowMaximizeCommand;
    class WindowMoveCommand;
    class WindowRestoreCommand;
    class WindowShowCommand;
    class WindowSizeCommand;
    class WindowTitleCommand;
    class WindowUnfloatCommand;

    /*! \brief GLFW Event Manager
    
        \note There should only be ONE of these (might combine it with AppGLFW TBH....)
    */
    class GLFWManager : public Manager {
        YQ_TACHYON_DECLARE(GLFWManager, Manager)
    public:
    
        GLFWManager(const Param& p = {});
        ~GLFWManager();
    
        static GLFWManager*         manager();
        
        static bool                 raw_mouse_motion_supported();
        
        static void                 init_info();
        
        static bool                 has_viewers();


    protected:
        
        virtual void                tick(const Context&) override;
        
        //virtual void                polling(unit::Second) override;

    private:
    
        struct JoystickData; //< Not to be confused with joystick class
        struct Window;
        struct Common;
        static Common&  common();
        friend class Viewer;
        friend class Application;
        
        static Param                _augment(const Param&);
        
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
        
        static void _poll(Joystick);
        static void _install(Joystick);

        static void _poll(unit::Second);
        
        static ModifierKeys _modifiers(GLFWwindow*);
        static MouseButtons _buttons(GLFWwindow*);
        static Vector2D     _mouse_pos(GLFWwindow*);
        static void         _update(GLFWwindow*, ViewerState&);
        
        static void     _aspect(Window*, const Size2I&);
        static void     _attention(Window*);
        static void     _destroy(Window*);
        static void     _float(Window*);
        static void     _focus(Window*);
        static void     _hide(Window*);
        static void     _iconify(Window*);
        static void     _maximize(Window*);
        static void     _move(Window*, const Vector2I&);
        static void     _restore(Window*);
        static void     _show(Window*);
        static void     _size(Window*, const Size2I&);
        static void     _title(Window*, const std::string&);
        static void     _unfloat(Window*);
        //static Viewer*  _viewer(GLFWwindow*);
        static Window*  _window(Viewer*);
        static Window*  _window(GLFWwindow*);
        
        static void     _cursor_capture(Window*);
        static void     _cursor_disable(Window*);
        static void     _cursor_hide(Window*);
        static void     _cursor_normal(Window*);
        
        void    cmd_aspect(const WindowAspectCommand&);
        void    cmd_attention(const WindowAttentionCommand&);
        void    cmd_destroy(const WindowDestroyCommand&);
        void    cmd_cursor_capture(const WindowCursorCaptureCommand&);
        void    cmd_cursor_disable(const WindowCursorDisableCommand&);
        void    cmd_cursor_hide(const WindowCursorHideCommand&);
        void    cmd_cursor_normal(const WindowCursorNormalCommand&);
        void    cmd_float(const WindowFloatCommand&);
        void    cmd_focus(const WindowFocusCommand&);
        void    cmd_hide(const WindowHideCommand&);
        void    cmd_iconify(const WindowIconifyCommand&);
        void    cmd_maximize(const WindowMaximizeCommand&);
        void    cmd_move(const WindowMoveCommand&);
        void    cmd_restore(const WindowRestoreCommand&);
        void    cmd_show(const WindowShowCommand&);
        void    cmd_size(const WindowSizeCommand&);
        void    cmd_title(const WindowTitleCommand&);
        void    cmd_unfloat(const WindowUnfloatCommand&);

        //! Starts up the viewer (ie, creates the GLFWwindow, passes it off to the viewer's startup routine)
        static std::error_code      win_start(Viewer*);
        static std::error_code      win_show(Viewer*);
        static std::error_code      win_hide(Viewer*);
        static std::error_code      win_destroy(Viewer*);

    };
}
