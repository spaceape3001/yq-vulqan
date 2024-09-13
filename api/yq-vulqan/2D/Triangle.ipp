////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Triangle.hpp"

#include <yq-toolbox/basic/Logging.hpp>
#include <yq-toolbox/shape/TriangleData.hpp>
#include <yq-toolbox/shape/shape_utils.hpp>

#include <yq-vulqan/render/Render3DWriter.hpp>
#include <yq-vulqan/shader/Shader.hpp>

#include <yq-toolbox/vector/Vector3.hxx>

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