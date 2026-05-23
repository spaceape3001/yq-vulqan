////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/meta/MetaBinder.hpp>

namespace yq::tachyon {
    enum class DrawMode {
        Auto,
        Color,
        // BiColor,        // bi color (with grayscale texture)
        // Face,           // Solid color per face (TBD)
        Gradient,       // nice between corners
        Material,
        Texture         // texture (only)
    };
}
YQ_TYPE_DECLARE(yq::tachyon::DrawMode)
