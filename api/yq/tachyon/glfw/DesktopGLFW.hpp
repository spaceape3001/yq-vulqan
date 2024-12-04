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
        static constexpr size_t nMaxJoysticks  = 16;
        
        using joysticks_t   = std::array<JoystickGLFW*, nMaxJoysticks>;
        using windows_t     = std::vector<WindowGLFW*>;
        
        using std_cursor_lookup = std::map<StdCursor, CursorID>;
        
        //! Joysticks (number comes from GLFW)
        joysticks_t         m_joysticks;
        glfw_cursor_map     m_cursors;
        std_cursor_lookup   m_stdCursors;
        windows_t           m_windows;
        KeyboardGLFW*       m_keyboard  = nullptr;
        
        //! Primary monitor
        MonitorGLFW*        m_monitor   = nullptr;
        glfw_monitor_map    m_monitors;
        MouseGLFW*          m_mouse     = nullptr;
        ControlFlags        m_control;
        Stage               m_stage     = Stage::Uninit;
        
        // TRUE if an insertion occured
        bool _install(joystick_t, int);
        bool _install(cursor_t, StdCursor, int);
    };
}
