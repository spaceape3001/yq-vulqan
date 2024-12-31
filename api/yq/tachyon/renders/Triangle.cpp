////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Triangle.hpp"

#include <yq/core/Logging.hpp>
#include <yq/shape/TriangleData.hpp>
#include <yq/shape/shape_utils.hpp>

#include <yq/tachyon/api/Rendered3InfoWriter.hpp>
#include <yq/tachyon/api/Shader.hpp>

#include <yq/vector/Vector3.hxx>

namespace yq::tachyon {
    void Triangle3::init_info()
    {
        auto w = writer<Triangle3>();
        w.description("Triangle in three dimensions");
        
        {
            auto& p = w.pipeline();
            
            p.shader("assets/colored.vert");
            p.shader("assets/colored.frag");

            p.vertex(&Triangle3::m_vertex, DataActivity::FIXED)
                .attribute(&ColorVertexData::position)
                .attribute(&ColorVertexData::color)
            ;
            
            p.push_full();
        }
    }

    Triangle3::Triangle3(const TriangleData<ColorVertex2D>&tri, const Param& p) : Rendered3(p)
    {
        m_vertex    = { tri.a, tri.b, tri.c};
        //m_draw.vertex_count  = 3;
    }
    
    Triangle3::~Triangle3()
    {
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Triangle3)
