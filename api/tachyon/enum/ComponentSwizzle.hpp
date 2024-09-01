////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/basic/Enum.hpp>
#include <yq/meta/InfoBinder.hpp>

namespace yq::tachyon {
    YQ_ENUM(ComponentSwizzle, ,
        Identity    = 0,
        Zero        = 1,
        One         = 2,
        Red         = 3,
        Green       = 4,
        Blue        = 5,
        Alpha       = 6
    )
}

YQ_TYPE_DECLARE(yq::tachyon::ComponentSwizzle)
