////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

//  This contains some vertex helpers

#include <yq/color/RGB.hpp>
#include <yq-toolbox/vector/Vector3.hpp>

namespace yq::tachyon {
    struct ColorVertexData;
    
    /*! \brief Used for encapsulating color and position information for a vertex in 3D
    */
    struct ColorVertex3D {
    
        //! The position
        Vector3D        position;
        
        //! The color
        RGB3U8          color;
        
        //! Defaulted equality
        constexpr bool operator==(const ColorVertex3D&) const noexcept = default;
        
        //! Convert to GLM based vertex data
        operator ColorVertexData() const;
    };
}
