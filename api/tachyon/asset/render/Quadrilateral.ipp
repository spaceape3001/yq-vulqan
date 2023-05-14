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
        static IB1<uint16_t> kIndices({ 0, 1, 2, 2, 3, 0 });
    
        auto w = writer<Quadrilateral>();
        
        {
            auto p = w.pipeline();
            
            p.shader("assets/colored.vert");
            p.shader("assets/colored.frag");

            p.vertex(&Quadrilateral::m_vertex, DataActivity::FIXED)
                .attribute(&ColorVertexData::position)
                .attribute(&ColorVertexData::color)
            ;
            
            p.index(kIndices, DataActivity::COMMON);
            p.push_full();
        }
    }

    Quadrilateral::Quadrilateral(const QuadrilateralData<ColorVertex2D>&quad)
    {
        m_vertex = { quad.a, quad.b, quad.c, quad.d};
    }
    
    Quadrilateral::~Quadrilateral()
    {
    }
    
    YQ_INVOKE(
        Quadrilateral::initInfo();
    );
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::Quadrilateral)
