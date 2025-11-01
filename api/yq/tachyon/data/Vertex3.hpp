////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/color/RGBA.hpp>
#include <yq/math/UV.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {
    //! Nominal "vertex" information for data exchange
    struct Vertex³ {
        Vector3D        point  = {};    // 24 bytes
        UV2F            uv     = {};    // 8 bytes
        RGBA4F          color  = {};    // 16 bytes
        Vector3F        normal = {};    // 12 bytes
        
        constexpr bool operator==(const Vertex³&) const noexcept = default;
    };
    
    struct ColorVertex2D;
    struct ColorVertex3D;
    
    Vertex³     vertex³(const ColorVertex2D&);
    Vertex³     vertex³(const ColorVertex3D&);
}

YQ_TYPE_DECLARE(yq::tachyon::Vertex³)
