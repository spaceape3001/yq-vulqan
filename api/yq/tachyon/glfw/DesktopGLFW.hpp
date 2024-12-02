////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Desktop.hpp>
#include <array>
#include <vector>

namespace yq::tachyon {
    struct AppCreateInfo;
    
    class JoystickGLFW;
    class KeyboardGLFW;
    class MonitorGLFW;
    class MouseGLFW;
    class WindowGLFW;

    class DesktopGLFW : public Desktop {
        YQ_TACHYON_DECLARE(DesktopGLFW, Desktop);
    public:
    
    
        DesktopGLFW(const AppCreateInfo&, const Param& p=Param());
        ~DesktopGLFW();
        
        virtual Execution tick(Context&) override;

        static void init_info();
        
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
        
        //! Joysticks (number comes from GLFW)
        joysticks_t     m_joysticks;
        windows_t       m_windows;
        KeyboardGLFW*   m_keyboard  = nullptr;
        MonitorGLFW*    m_monitor   = nullptr;
        MouseGLFW*      m_mouse     = nullptr;
        ControlFlags    m_control;
        Stage           m_stage     = Stage::Uninit;
    };
}
