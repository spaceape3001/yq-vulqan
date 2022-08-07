////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Triangle.hpp"
#include <math/TriangleData.hpp>
#include <math/shape_utils.hpp>
#include <engine/render/RenderWriter.hpp>
#include <engine/Shader.hpp>
#include <basic/preamble.hpp>

namespace yq {
    namespace asset {
        void Triangle::initInfo()
        {
            auto w = writer<Triangle>();
            auto p = w.pipeline();
            
            p.shader("assets/colored.vert");
            p.shader("assets/colored.frag");

            p.static_vertex(&Triangle::m_vertex, "vertex"sv)
                .attribute(&ColorVertexData::position)
                .attribute(&ColorVertexData::color)
            ;
            
            p.push(yq::engine::PushConfigType::Full);
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
YQ_OBJECT_IMPLEMENT(yq::asset::Triangle)
