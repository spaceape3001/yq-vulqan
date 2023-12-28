////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <0/basic/Enum.hpp>
#include <0/meta/InfoBinder.hpp>

namespace yq::tachyon {

    /*! \brief Cull Mode
    
        Cull mode for vulkan/pipeline
    */
    YQ_ENUM(CullMode, , 
    
        //! No culling
        None    = 0,
        
        //! Cull front
        Front   = 1,
        
        //! Cull back
        Back    = 2,
        
        //! Cull both
        FrontBack   = 3
    )
}

YQ_TYPE_DECLARE(yq::tachyon::CullMode)
