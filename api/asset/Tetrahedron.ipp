////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Tetrahedron.hpp"
#include <math/TetrahedronData.hpp>
#include <math/shape_utils.hpp>
#include <engine/render/RenderWriter.hpp>
#include <engine/Shader.hpp>
#include <basic/preamble.hpp>

namespace yq {
    namespace asset {
        void Tetrahedron::initInfo()
        {
            static const uint16_t   kIndices[] = { 1, 2, 3, 0, 3, 2, 0, 1, 3, 0, 2, 1 };
        
            auto w = writer<Tetrahedron>();
            auto p = w.pipeline();
            
            p.shader("assets/colored.vert");
            p.shader("assets/colored.frag");

            p.static_vertex(&Tetrahedron::m_vertex, "vertex"sv)
                .attribute(&ColorVertexData::position)
                .attribute(&ColorVertexData::color)
            ;
            
            p.common_index(kIndices, "index"sv);
            
            p.push(yq::engine::PushConfigType::Full);
        }

        Tetrahedron::Tetrahedron(const TetrahedronData<ColorVertex3D>&tri)
        {
            m_vertex[0] = tri.a;
            m_vertex[1] = tri.b;
            m_vertex[2] = tri.c;
            m_vertex[3] = tri.d;
        }
        
        Tetrahedron::~Tetrahedron()
        {
        }
        
        YQ_INVOKE(
            Tetrahedron::initInfo();
        );
    }
}
YQ_OBJECT_IMPLEMENT(yq::asset::Tetrahedron)
