////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Triangle.hpp"
#include <0/math/shape/TriangleData.hpp>
#include <0/math/shape/shape_utils.hpp>
#include <tachyon/Render3DWriter.hpp>
#include <tachyon/Shader.hpp>
#include <0/basic/preamble.hpp>
#include <yq/basic/Logging.hpp>

namespace yq::tachyon {
    void Triangle::initInfo()
    {
        auto w = writer<Triangle>();
        
        {
            auto p = w.pipeline();
            
            p.shader("assets/colored.vert");
            p.shader("assets/colored.frag");

            p.vertex(&Triangle::m_vertex, DataActivity::FIXED)
                .attribute(&ColorVertexData::position)
                .attribute(&ColorVertexData::color)
            ;
            
            p.push_full();
        }
    }

    Triangle::Triangle(const TriangleData<ColorVertex2D>&tri)
    {
        m_vertex    = { tri.a, tri.b, tri.c};
        m_draw.vertex_count  = 3;
    }
    
    Triangle::~Triangle()
    {
    }
    
    YQ_INVOKE(
        Triangle::initInfo();
    );
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::Triangle)
