////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/rendered/ColorTetrahedron3.hpp>
#include <tachyon/logging.hpp>

#include <tachyon/resource/Shader.hpp>
#include <tachyon/api/Rendered3MetaWriter.hpp>

#include <tachyon/aspect/AColorWriter.hxx>

namespace yq::tachyon {
    void ColorTetrahedron³::init_meta()
    {
        auto w = writer<ColorTetrahedron³>();
        w.description("Color Tetrahedron in 3D");
        w.category("Shape");
        
        AColor::init_meta(w);

        auto& p = w.pipeline();
        
        p.shader("resources/shape3/color.vert");
        p.shader("resources/shape3/color.frag");

        p.vertex(&ColorTetrahedron³::m_vbo, DataActivity::DYNAMIC)
            .attribute(&VertexS::position)
        ;

        p.uniform(&ColorTetrahedron³::m_ubo, DataActivity::DYNAMIC);
        p.index(s_indices, DataActivity::COMMON);
        p.push_full();
    }

    ColorTetrahedron³::ColorTetrahedron³(const Vertex³&a, const Vertex³&b, const Vertex³&c, const Vertex³&d, const Param&p) : 
        Tetrahedron³(a,b,c,d,p)
    {
        m_color = p.color;
    }
  
    ColorTetrahedron³::ColorTetrahedron³(const TetrahedronData<ColorVertex3D>&data, const Param& p) : Tetrahedron³(data, p)
    {
        m_color = p.color;
    }

    ColorTetrahedron³::ColorTetrahedron³(const Param&p) : Tetrahedron³(kDefVertex1, kDefVertex2, kDefVertex3, kDefVertex4, p)
    {
        m_color = p.color;
    }

    ColorTetrahedron³::~ColorTetrahedron³()
    {
    }

    void    ColorTetrahedron³::rebuild()
    {
        m_vbo    = {
            vs(vertex1()), vs(vertex2()), vs(vertex3()), vs(vertex4())
        };
        m_ubo   = {
            .color  = m_color
        };
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::ColorTetrahedron³)
