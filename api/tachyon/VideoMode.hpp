////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/preamble.hpp>
#include <yq-toolbox/color/RGB.hpp>
#include <yq-toolbox/shape/Size2.hpp>

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
