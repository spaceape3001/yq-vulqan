////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <vector>
#include <string>
#include <math/preamble.hpp>
#include <tachyon/preamble.hpp>

namespace yq::tachyon {
    class Monitor {
    public:
        static std::vector<Monitor>   enumerate();
        
        //! Returns the primary monitor
        static Monitor                primary();

        constexpr Monitor() noexcept = default;
        
        //! Underlying GLFW Monitor pointer
        GLFWmonitor*            monitor() const { return m_monitor; }
    
        //! Name of the monitor
        std::string             name() const;
        
        //! Position of the monitor
        Vector2I                position() const;
        
        //! Physical size of monitor (in MM)
        Size2I                  phys_size_mm() const;
        
        //! Scale of the montior
        Vector2F                scale() const;
        
        //! Current video mode
        VideoMode               video_mode_current() const;
        
        //! All video modes
        std::vector<VideoMode>  video_modes_available() const;
    
        /*! Monitor's "Work area"
        
            This work area is returned in screen coordinates.
        */
        Rectangle2I             work_area() const;
        
        constexpr operator bool () const noexcept { return m_monitor != nullptr; }
        constexpr bool    operator==(const Monitor&) const noexcept = default;
    
    private:
        friend class Window;
        
        GLFWmonitor *m_monitor = nullptr;
        constexpr Monitor(GLFWmonitor *m) noexcept : m_monitor(m) {}
    };

}
