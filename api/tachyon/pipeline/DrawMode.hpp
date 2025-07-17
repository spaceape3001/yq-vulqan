////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Enum.hpp>
#include <yq/meta/MetaBinder.hpp>

namespace yq::tachyon {
    YQ_ENUM(DrawMode, , 
        Auto,
        Color,
        BiColor,    // bi color (with grayscale texture)
        Gradient,   // nice between corners
        Texture
    )
}
YQ_TYPE_DECLARE(yq::tachyon::DrawMode)
