////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-toolbox/basic/Enum.hpp>
#include <yq-toolbox/basic/Flag.hpp>
#include <yq-toolbox/meta/InfoBinder.hpp>

namespace yq::tachyon {
    /*! \brief Color Component
    
        Used in swizzling, this specifies color components.  
        Values are based on vulkan specification.
    */
    YQ_ENUM(ColorComponent, , 
    
        //! Red
        Red     = 0,
        
        //! Green
        Green   = 1,
        
        //! Blue
        Blue    = 2,
        
        //! Alpha
        Alpha   = 3
    )
    
    /*! \brief Color Component Flags
    
        Useful when needing to bit flag color components
    */
    using ColorComponentFlags   = Flag<ColorComponent>;
}

YQ_TYPE_DECLARE(yq::tachyon::ColorComponent)
YQ_TYPE_DECLARE(yq::tachyon::ColorComponentFlags)
