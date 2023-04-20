////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

//  This contains some vertex helpers

#include <glm/glm.hpp>
#include <tachyon/data/ColorVertex2D.hpp>
#include <tachyon/data/ColorVertex3D.hpp>
#include <math/vector/Vector3.hpp>
#include <math/color/RGBA.hpp>

namespace yq::tachyon {
    struct ColorVertexData {
        glm::vec3       position;
        glm::vec4       color;
        
        bool operator == (const ColorVertexData&) const = default;
    };

    inline ColorVertex2D::operator ColorVertexData() const
    {
        return { (glm::dvec3) xy(position, 0.), rgba((RGB3F) color, 1.f) };
    }

    inline ColorVertex3D::operator ColorVertexData() const
    {
        return { (glm::dvec3) position, rgba((RGB3F) color, 1.f) };
    }
}
