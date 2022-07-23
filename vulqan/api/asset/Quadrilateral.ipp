////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Quadrilateral.hpp"
#include <math/QuadrilateralData.hpp>
#include <math/shape_math.hpp>
#include <engine/render/RenderWriter.hpp>
#include <engine/Shader.hpp>
#include <basic/preamble.hpp>

namespace yq {
    namespace asset {
        void Quadrilateral::initInfo()
        {
            static const uint16_t   kIndices[] = { 0, 1, 2, 2, 3, 0 };
        
            auto w = writer<Quadrilateral>();
            auto p = w.pipeline();
            
            p.shader("assets/colored.vert");
            p.shader("assets/colored.frag");

            p.static_vertex(&Quadrilateral::m_vertex, "vertex"sv)
                .attribute(&ColorVertexData::position)
                .attribute(&ColorVertexData::color)
            ;
            
            p.common_index(kIndices, "index"sv);
            
            p.push(yq::engine::PushConfigType::Full);
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
}
YQ_OBJECT_IMPLEMENT(yq::asset::Quadrilateral)
