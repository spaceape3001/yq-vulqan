////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-toolbox/basic/Enum.hpp>
#include <yq-toolbox/meta/InfoBinder.hpp>

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
