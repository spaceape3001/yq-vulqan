////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <0/basic/Enum.hpp>
#include <0/meta/InfoBinder.hpp>

namespace yq::tachyon {

    /*! \brief Sampler filter
    
        This controls the sampler filter
    */
    YQ_ENUM(SamplerFilter, ,
        //! Nearest pixel
        Nearest     = 0,
        //! Linear interpolation?
        Linear      = 1,
        //! Cubic interpolation?
        Cubic       = 1000015000
    )
}
YQ_TYPE_DECLARE(yq::tachyon::SamplerFilter)
