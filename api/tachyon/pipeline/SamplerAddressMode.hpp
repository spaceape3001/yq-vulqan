////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Enum.hpp>
#include <yq/meta/MetaBinder.hpp>

namespace yq::tachyon {
    /*! \brief Sampler's out-of-bounds conditions
    
        How the sampler deals with u,v < 0 and/or u,v > 1
    */
    YQ_ENUM(SamplerAddressMode, ,
    
        //! Periodic
        Repeat  = 0,
        
        //! Mirrored but periodic
        MirroredRepeat = 1,
        
        //! Clamps to the edge
        ClampToEdge = 2,
        
        //! Clamps to the border
        ClampToBorder = 3,
        
        //! Mirror clamp to edge
        //! \note Needs extension to work
        MirrorClampToEdge = 4
    )
}
YQ_TYPE_DECLARE(yq::tachyon::SamplerAddressMode)
