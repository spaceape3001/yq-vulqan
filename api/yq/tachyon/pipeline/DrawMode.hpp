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
        // BiColor,        // bi color (with grayscale texture)
        // Face,           // Solid color per face (TBD)
        Gradient,       // nice between corners
        Material,
        Texture,        // texture (only)
        
        DbgBlack,
        DbgBlue,
        DbgCyan,
        DbgGray,
        DbgGreen,
        DbgMagenta,
        DbgOrange,
        DbgRed,
        DbgWhite,
        DbgYellow
    )
}
YQ_TYPE_DECLARE(yq::tachyon::DrawMode)
