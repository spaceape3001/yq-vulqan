////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/Manager.hpp>
#include <yq/post/Dispatcher.hpp>
#include <yq/tachyon/enum/ModifierKey.hpp>
#include <yq/tachyon/enum/MouseButton.hpp>
#include <yq/typedef/vector2.hpp>

struct GLFWwindow;
struct GLFWmonitor;

namespace yq::tachyon {
    class Viewer;
    class Joystick;
    
    struct ViewerState;
    
    struct ViewerInitData;

    /*! \brief GLFW Event Manager
    
        \note There should only be ONE of these (might combine it with AppGLFW TBH....)
    */
    class GLFWManager : public Manager {
        YQ_OBJECT_DECLARE(GLFWManager, Manager)
    public:
    
        GLFWManager(const Param& p = {});
        ~GLFWManager();
    
        static void                 remove(Viewer&);
        static GLFWManager*         manager();
        
        static bool                 raw_mouse_motion_supported();

    protected:
        
        virtual void                polling(unit::Second) override;

    private:

        struct JoystickData; //< Not to be confused with joystick class
        struct ViewerData;
        struct Common;
        static Common&  common();
        friend class Viewer;
        
        static ViewerInitData       create(Viewer*, const ViewerCreateInfo&);
        static void                 remove(Viewer*);

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
        
        //static void joystick_initialize(Joystick);
        //static void joystick_kill(Joystick);

    };
}
