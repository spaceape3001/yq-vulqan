////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Tetrahedron.hpp"
#include <0/math/shape/TetrahedronData.hpp>
#include <0/math/shape/shape_utils.hpp>
#include <tachyon/Render3DWriter.hpp>
#include <tachyon/Shader.hpp>
#include <0/basic/preamble.hpp>

namespace yq::tachyon {
    void Tetrahedron::initInfo()
    {
        static const uint16_t   kIndices[] = { 1, 2, 3, 0, 3, 2, 0, 1, 3, 0, 2, 1 };
        static IBO<uint16_t>    indices(kIndices);
    
        auto w = writer<Tetrahedron>();
        {
            auto p = w.pipeline();
            
            p.shader("assets/colored.vert");
            p.shader("assets/colored.frag");

            p.vertex(&Tetrahedron::m_vertex, DataActivity::FIXED)
                .attribute(&ColorVertexData::position)
                .attribute(&ColorVertexData::color)
            ;
            
            p.index(indices, DataActivity::COMMON);
            p.push_full();
        }
    }

    Tetrahedron::Tetrahedron(const TetrahedronData<ColorVertex3D>&tri)
    {
        m_vertex    = { tri.a, tri.b, tri.c, tri.d};
    }
    
    Tetrahedron::~Tetrahedron()
    {
    }
    
    YQ_INVOKE(
        Tetrahedron::initInfo();
    );
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::Tetrahedron)
