////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Quadrilateral.hpp"
#include <math/shape/QuadrilateralData.hpp>
#include <math/vector/Vector3.hxx>
#include <math/shape/shape_utils.hpp>
#include <tachyon/scene/Render3DWriter.hpp>
#include <tachyon/viz/Shader.hpp>
#include <basic/preamble.hpp>

namespace yq::tachyon {
    void Quadrilateral::initInfo()
    {
        static const uint16_t   kIndices[] = { 0, 1, 2, 2, 3, 0 };
    
        auto w = writer<Quadrilateral>();
        
        {
            auto p = w.pipeline();
            
            p.shader("assets/colored.vert");
            p.shader("assets/colored.frag");

            p.fixed_vertex(&Quadrilateral::m_vertex)
                .attribute(&ColorVertexData::position)
                .attribute(&ColorVertexData::color)
            ;
            
            p.common_index(kIndices);
            p.push_full();
        }
    }

    Quadrilateral::Quadrilateral(const QuadrilateralData<ColorVertex2D>&tri)
    {
        m_vertex[0] = tri.a;
        m_vertex[1] = tri.b;
        m_vertex[2] = tri.c;
        m_vertex[3] = tri.d;
    }
    
    Quadrilateral::~Quadrilateral()
    {
    }
    
    YQ_INVOKE(
        Quadrilateral::initInfo();
    );
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::Quadrilateral)
