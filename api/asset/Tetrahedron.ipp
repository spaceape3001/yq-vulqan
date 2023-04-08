////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Tetrahedron.hpp"
#include <math/shape/TetrahedronData.hpp>
#include <math/shape/shape_utils.hpp>
#include <tachyon/scene/Render3DWriter.hpp>
#include <tachyon/gfx/Shader.hpp>
#include <basic/preamble.hpp>

namespace yq {
    namespace tachyon {
        void Tetrahedron::initInfo()
        {
            static const uint16_t   kIndices[] = { 1, 2, 3, 0, 3, 2, 0, 1, 3, 0, 2, 1 };
        
            auto w = writer<Tetrahedron>();
            {
                auto p = w.pipeline();
                
                p.shader("assets/colored.vert");
                p.shader("assets/colored.frag");

                p.fixed_vertex(&Tetrahedron::m_vertex)
                    .attribute(&ColorVertexData::position)
                    .attribute(&ColorVertexData::color)
                ;
                
                p.common_index(kIndices);
                p.push_full();
            }
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
YQ_OBJECT_IMPLEMENT(yq::tachyon::Tetrahedron)
