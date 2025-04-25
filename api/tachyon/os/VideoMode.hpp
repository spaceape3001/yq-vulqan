////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/color/RGB.hpp>
#include <yq/shape/Size2.hpp>

struct GLFWvidmode;

namespace yq::tachyon {
    /*! \brief Video mode information
    
        Video mode information about what a monitor supports
    */
    struct VideoMode {
    
        //! Size of the video mode
        Size2I      size            = {};
        
        //! Bit counts for the monitor
        RGB3I       bits            = {};
        
        //! Refresh rate
        int         refresh_rate    = 0;
        
        //! Default constructor
        VideoMode(){}
        
        //! Construction from GLFWvidmode
        VideoMode(const GLFWvidmode&);
        
        //! Equality operator (defaulted)
        constexpr bool    operator==(const VideoMode&) const noexcept = default;
    };
}
