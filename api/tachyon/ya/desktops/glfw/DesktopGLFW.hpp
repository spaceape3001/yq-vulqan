////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/os/Desktop.hpp>
#include <ya/desktops/glfw/glfw.hpp>
#include <array>
#include <vector>

namespace yq::tachyon {
    struct AppCreateInfo;
    
    class DesktopGLFW : public Desktop {
        YQ_TACHYON_DECLARE(DesktopGLFW, Desktop);
    public:
    
    
        DesktopGLFW(const AppCreateInfo&, const Param& p=Param());
        ~DesktopGLFW();
        
        static void init_info();

        virtual CursorID    cursor(StdCursor) const override;

        using Desktop::create;
        virtual Window*     create(window_k, const ViewerCreateInfo&) override;
        WindowGLFW*         create_window(const ViewerCreateInfo&);
        
        //virtual bool        is_running() const override;

    protected:
        virtual PostAdvice  advise(const Post&) const override;

        Execution    tick(const Context&) override;
        Execution    setup(const Context&) override;
        Execution    teardown(const Context&) override;

    private:
        friend class WindowGLFW;
        friend class JoystickGLFW;
        
        
        static DesktopGLFW*     s_desktop;
        static void callback_joystick(int jid, int event);
        static void callback_monitor(GLFWmonitor* monitor, int event);
        
        using std_cursor_lookup = std::map<StdCursor, CursorID>;
        
        //! Joysticks (number comes from GLFW)
        glfw_joystick_array     m_joysticks;
        glfw_gamepad_array      m_gamepads;
        glfw_cursor_map         m_cursors;
        std_cursor_lookup       m_stdCursors;
        glfw_window_map         m_windows;
        KeyboardGLFW*           m_keyboard  = nullptr;
        TypedID                 m_focus;
        
        //! Primary monitor
        MonitorGLFW*            m_monitor   = nullptr;
        glfw_monitor_map        m_monitors;
        MouseGLFW*              m_mouse     = nullptr;
        bool                    m_init      = false;
        
        // TRUE if an insertion occured
        void _install(cursor_k, all_k);
        bool _install(cursor_k, StdCursor, int);
        void _install(joystick_k, all_k);
        bool _install(joystick_k, int, bool sendEvent=false);
        void _install(monitor_k, all_k);
        bool _install(monitor_k, GLFWmonitor*);
        
        MonitorGLFW*    _monitor(MonitorID);
        
        void _uninstall(joystick_k, int);
        void _uninstall(monitor_k, GLFWmonitor*);
    };
}
