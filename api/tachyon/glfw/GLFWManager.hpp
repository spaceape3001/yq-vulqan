////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/app/Manager.hpp>
#include <yq/post/Dispatcher.hpp>

struct GLFWwindow;
struct GLFWmonitor;

namespace yq::tachyon {
    class Viewer;
    class Joystick;

    /*! \brief GLFW Event Manager
    
        \note There should only be ONE of these (might combine it with AppGLFW TBH....)
    */
    class GLFWManager : public Manager {
        YQ_OBJECT_DECLARE(GLFWManager, Manager)
    public:
    
        GLFWManager(const Param& p = {});
        ~GLFWManager();
    
        virtual void    polling(unit::Second) override;
        static GLFWManager*        manager();
        
    private:
        friend class Viewer;
        
        static Param    _augment(const Param&);
        
        #if 0
        static void callback_character(GLFWwindow* window, unsigned int codepoint);
        static void callback_cursor_enter(GLFWwindow* window, int entered);
        static void callback_cursor_position(GLFWwindow* window, double xpos, double ypos);
        static void callback_drop(GLFWwindow* window, int count, const char** paths);
        static void callback_framebuffer_size(GLFWwindow* window, int width, int height);
        #endif
        
        static void callback_joystick(int jid, int event);
        
        #if 0
        static void callback_key(GLFWwindow* window, int key, int scancode, int action, int mods);
        #endif
        
        static void callback_monitor(GLFWmonitor* monitor, int event);
        
        #if 0
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
        #endif
        
        static void joystick_initialize(Joystick);
        static void joystick_kill(Joystick);

        struct Joystix; //< Not to be confused with joystick class
        struct Common;
        static Common&  common();
        friend class Window;
    };
}
