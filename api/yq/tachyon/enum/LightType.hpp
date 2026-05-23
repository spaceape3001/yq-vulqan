////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/meta/MetaBinder.hpp>

namespace yq::tachyon {
    // Wish I didn't have to enumerate, but I do...
    
    enum class LightType {
        Unknown,
        Ambient,
        Unidirectional,
        Plane,
        Point,
        Spot
    };
}

YQ_TYPE_DECLARE(yq::tachyon::LightType)

