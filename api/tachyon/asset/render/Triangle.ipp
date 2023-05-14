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
#include <tachyon/viz/Shader.hpp>
#include <basic/preamble.hpp>
#include <basic/Logging.hpp>

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
        
        yInfo() << "" <<  w.meta().pipeline()->config();
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
