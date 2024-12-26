////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Triangle.hpp"

#include <yq/core/Logging.hpp>
#include <yq/shape/TriangleData.hpp>
#include <yq/shape/shape_utils.hpp>

#include <yq/tachyon/api/Render³InfoWriter.hpp>
#include <yq/tachyon/api/Shader.hpp>

#include <yq/vector/Vector3.hxx>

namespace yq::tachyon {
    void Triangle³::init_info()
    {
        auto w = writer<Triangle³>();
        w.description("Triangle in three dimensions");
        
        {
            auto& p = w.pipeline();
            
            p.shader("assets/colored.vert");
            p.shader("assets/colored.frag");

            p.vertex(&Triangle³::m_vertex, DataActivity::FIXED)
                .attribute(&ColorVertexData::position)
                .attribute(&ColorVertexData::color)
            ;
            
            p.push_full();
        }
    }

    Triangle³::Triangle³(const TriangleData<ColorVertex2D>&tri)
    {
        m_vertex    = { tri.a, tri.b, tri.c};
        //m_draw.vertex_count  = 3;
    }
    
    Triangle³::~Triangle³()
    {
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Triangle³)
