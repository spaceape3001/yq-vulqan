////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

//  This contains some vertex helpers

#include <math/color/RGB.hpp>
#include <math/vector/Vector2.hpp>

namespace yq {
    namespace tachyon {
        struct ColorVertexData;
        
        /*! \brief Used for encapsulating color and position information
        */
        struct ColorVertex2D {
        
            //! Position
            Vector2D        position;
            
            //! Color
            RGB3U8          color;
            
            //! Equality operator
            constexpr bool operator==(const ColorVertex2D&) const = default;
            
            //! Operator to reduce to color vertex data (GLM)
            operator ColorVertexData() const;
        };
    }
}

