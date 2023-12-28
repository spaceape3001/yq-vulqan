////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <0/basic/Enum.hpp>
#include <0/meta/InfoBinder.hpp>

namespace yq::tachyon {

    /*! \brief Sampler Mipmap Mode
    */
    YQ_ENUM(SamplerMipmapMode, ,
        //! Nearest value
        Nearest = 0,
        //! Linear interpolation
        Linear = 1
    )
}

YQ_TYPE_DECLARE(yq::tachyon::SamplerMipmapMode)
