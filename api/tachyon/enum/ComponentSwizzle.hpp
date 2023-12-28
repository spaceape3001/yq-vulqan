////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <0/basic/Enum.hpp>
#include <0/meta/InfoBinder.hpp>

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
