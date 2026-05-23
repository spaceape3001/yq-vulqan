////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/meta/MetaBinder.hpp>

namespace yq::tachyon {
    /*! \brief Image tiling for vulkan
    */
    enum class ImageTiling {
        Optimal = 0,
        Linear = 1,
        DRMFormat = 1000158000
    };
}
YQ_TYPE_DECLARE(yq::tachyon::ImageTiling)
