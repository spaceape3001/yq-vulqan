////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once


#include <yq-toolbox/typedef/rectangle2.hpp>
#include <yq-toolbox/typedef/size2.hpp>
#include <yq-toolbox/typedef/vector2.hpp>

#include <vector>
#include <string>

struct GLFWmonitor;

namespace yq::tachyon {
    struct VideoMode;

    /*! \brief Wrapper for a monitor in GLFW 
    
        This is a simple wrapper to make it easier to interface with GLFW monitors w/o 
        the includes.
    */
    class Monitor {
    public:
    
        //! Enuemrate all the current monitors
        static std::vector<Monitor>   enumerate();
        
        //! Returns the primary monitor
        static Monitor                primary();

        //! Default constructor
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
        
        //! Tests for validity
        constexpr operator bool () const noexcept { return m_monitor != nullptr; }
        
        //! Tests for equality
        constexpr bool    operator==(const Monitor&) const noexcept = default;
    
    private:
        friend class Window;
        
        GLFWmonitor *m_monitor = nullptr;
        constexpr Monitor(GLFWmonitor *m) noexcept : m_monitor(m) {}
    };

}
