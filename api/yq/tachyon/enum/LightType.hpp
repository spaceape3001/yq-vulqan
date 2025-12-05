////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Enum.hpp>
#include <yq/meta/MetaBinder.hpp>

namespace yq::tachyon {
    // Wish I didn't have to enumerate, but I do...
    
    YQ_ENUM(LightType, , 
        Unknown,
        Omni,
        Plane,
        Point,
        Spot
    )
)

YQ_TYPE_DECLARE(yq::tachyon::LightType)

