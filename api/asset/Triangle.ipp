////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Triangle.hpp"
#include <math/shape/TriangleData.hpp>
#include <math/shape/shape_utils.hpp>
#include <tachyon/scene/Render3DWriter.hpp>
#include <tachyon/gfx/Shader.hpp>
#include <basic/preamble.hpp>

namespace yq {
    namespace tachyon {
        void Triangle::initInfo()
        {
            auto w = writer<Triangle>();
            
            {
                auto p = w.pipeline();
                
                p.shader("assets/colored.vert");
                p.shader("assets/colored.frag");

                p.fixed_vertex(&Triangle::m_vertex)
                    .attribute(&ColorVertexData::position)
                    .attribute(&ColorVertexData::color)
                ;
                
                p.push_full();
            }
        }

        Triangle::Triangle(const TriangleData<ColorVertex2D>&tri)
        {
            m_vertex[0] = tri.a;
            m_vertex[1] = tri.b;
            m_vertex[2] = tri.c;
            m_draw.vertex_count  = 3;
        }
        
        Triangle::~Triangle()
        {
        }
        
        YQ_INVOKE(
            Triangle::initInfo();
        );
    }
}
YQ_OBJECT_IMPLEMENT(yq::tachyon::Triangle)
