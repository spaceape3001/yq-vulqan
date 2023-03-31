////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/Enum.hpp>
#include <basic/meta/InfoBinder.hpp>

namespace yq {
    namespace tachyon {
        YQ_ENUM(BorderColor, , 
            FloatTransparentBlack = 0,
            IntTransparentBlack = 1,
            FloatOpaqueBlack = 2,
            IntOpaqueBlack = 3,
            FloatOpaqueWhite = 4,
            IntOpaqueWhite = 5,
            FloatCustomEXT = 1000287003,
            IntCustomEXT = 1000287004
        )

    }
}
YQ_TYPE_DECLARE(yq::tachyon::BorderColor)
