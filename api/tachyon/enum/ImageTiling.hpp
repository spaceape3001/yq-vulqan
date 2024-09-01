////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/basic/Enum.hpp>
#include <yq/meta/InfoBinder.hpp>

namespace yq::tachyon {
    /*! \brief Image tiling for vulkan
    */
    YQ_ENUM(ImageTiling, ,
        Optimal = 0,
        Linear = 1,
        DRMFormat = 1000158000
    )
}
YQ_TYPE_DECLARE(yq::tachyon::ImageTiling)
