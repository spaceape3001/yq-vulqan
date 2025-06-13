////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Enum.hpp>
#include <yq/meta/InfoBinder.hpp>

namespace yq::tachyon {
    YQ_ENUM(DrawMode, , 
        Auto,
        Color,
        Gradient,   // nice between corners
        Texture
    )
}
YQ_TYPE_DECLARE(yq::tachyon::DrawMode)
