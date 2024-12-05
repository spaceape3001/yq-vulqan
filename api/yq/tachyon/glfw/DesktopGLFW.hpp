////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Desktop.hpp>
#include <yq/tachyon/typedef/glfw.hpp>
#include <array>
#include <vector>

namespace yq::tachyon {
    struct AppCreateInfo;
    
    class DesktopGLFW : public Desktop {
        YQ_TACHYON_DECLARE(DesktopGLFW, Desktop);
    public:
    
    
        DesktopGLFW(const AppCreateInfo&, const Param& p=Param());
        ~DesktopGLFW();
        
        virtual Execution tick(Context&) override;

        static void init_info();

        virtual CursorID    cursor(StdCursor) const override;
        
        virtual bool        is_running() const override;

    private:
        enum class Stage {
            Uninit      = 0,
            Init,
            Running,
            Dead
        };
        
        
        Execution    _tick(Context&);
        Execution    _start(Context&);
        
        static DesktopGLFW*     s_desktop;
        static void callback_joystick(int jid, int event);
        static void callback_monitor(GLFWmonitor* monitor, int event);
        
        using std_cursor_lookup = std::map<StdCursor, CursorID>;
        
        //! Joysticks (number comes from GLFW)
        glfw_joystick_array     m_joysticks;
        glfw_cursor_map         m_cursors;
        std_cursor_lookup       m_stdCursors;
        glfw_window_map         m_windows;
        KeyboardGLFW*           m_keyboard  = nullptr;
        
        //! Primary monitor
        MonitorGLFW*            m_monitor   = nullptr;
        glfw_monitor_map        m_monitors;
        MouseGLFW*              m_mouse     = nullptr;
        ControlFlags            m_control;
        Stage                   m_stage     = Stage::Uninit;
        
        // TRUE if an insertion occured
        void _install(cursor_t, all_t);
        bool _install(cursor_t, StdCursor, int);
        void _install(joystick_t, all_t);
        bool _install(joystick_t, int);
        void _install(monitor_t, all_t);
        bool _install(monitor_t, GLFWmonitor*);
        
        void _uninstall(joystick_t, int);
        void _uninstall(monitor_t, GLFWmonitor*);
    };
}
