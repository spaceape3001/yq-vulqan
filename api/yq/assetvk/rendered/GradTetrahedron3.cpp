////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "GradTetrahedron3.hpp"
#include <yq/tachyon/logging.hpp>

#include <yq/color/colors.hpp>
#include <yq/shape/TetrahedronData.hpp>
#include <yq/shape/shape_utils.hpp>

#include <yq/tachyon/asset/Shader.hpp>
#include <yq/tachyon/api/Rendered3MetaWriter.hpp>

#include <yq/vector/Vector3.hxx>

#include <yq/tachyon/asset/Texture.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    void GradTetrahedron³::init_meta()
    {
        auto w = writer<GradTetrahedron³>();
        w.description("Tetrahedron in 3D with gradient colros");
        w.category("Shape");

        auto& p = w.pipeline();
        
        p.shader("yq/shape3/gradient.vert");
        p.shader("yq/shape3/gradient.frag");

        p.vertex(&GradTetrahedron³::m_vbo, {.activity=DYNAMIC})
            .attribute(&VertexC::position)
            .attribute(&VertexC::color)
        ;

        p.index(s_indices);
        p.push_full();
    }

    GradTetrahedron³::GradTetrahedron³(const Vertex³&a, const Vertex³&b, const Vertex³&c, const Vertex³&d, const Param&p) : 
        Tetrahedron³(a,b,c,d,p)
    {
    }
  
    GradTetrahedron³::GradTetrahedron³(const TetrahedronData<ColorVertex3D>&data, const Param& p) : 
        Tetrahedron³(data, p)
    {
    }

    GradTetrahedron³::GradTetrahedron³(const Param&p) : Tetrahedron³(p)
    {
    }

    GradTetrahedron³::~GradTetrahedron³()
    {
    }


    void    GradTetrahedron³::rebuild() 
    {
        m_vbo = {
            vc(vertex1()), vc(vertex2()), vc(vertex3()), vc(vertex4())
        };
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::GradTetrahedron³)
