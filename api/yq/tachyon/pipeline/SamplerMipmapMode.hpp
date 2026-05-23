////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/meta/MetaBinder.hpp>

namespace yq::tachyon {

    /*! \brief Sampler Mipmap Mode
    */
    enum class SamplerMipmapMode {
        //! Nearest value
        Nearest = 0,
        //! Linear interpolation
        Linear = 1
    };
}

YQ_TYPE_DECLARE(yq::tachyon::SamplerMipmapMode)
