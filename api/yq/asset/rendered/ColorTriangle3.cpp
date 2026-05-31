////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ColorTriangle3.hpp"
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/api/Rendered3MetaWriter.hpp>
#include <yq/tachyon/asset/Shader.hpp>
#include <yq/vector/Vector3.hxx>
#include <yq/tachyon/aspect/AColorWriter.hxx>

namespace yq::tachyon {
    void ColorTriangle³::init_meta()
    {
        auto w = writer<ColorTriangle³>();
        w.description("Color Triangle in 3D");
        w.category("Shape");

        auto& p = w.pipeline();
        p.shader("yq/shape3/color.vert");
        p.shader("yq/shape3/color.frag");

        p.vertex(&ColorTriangle³::m_vbo, {.activity=DYNAMIC})
            .attribute(&VertexS::position)
        ;
        p.uniform(&ColorTriangle³::m_ubo, {.activity=DYNAMIC});
        
        p.push_full();
    }
    
    ColorTriangle³::ColorTriangle³(const Param&p) : Triangle³(p)
    {
        m_color = p.color;
        rebuild();
    }

    ColorTriangle³::ColorTriangle³(const Vertex³&a, const Vertex³&b, const Vertex³&c, const Param&p) : 
        Triangle³(a,b,c,p)
    {
        m_color = p.color;
        rebuild();
    }
  
    ColorTriangle³::ColorTriangle³(const TriangleData<ColorVertex3D>&data, const Param& p) : 
        Triangle³(data, p)
    {
        m_color = p.color;
        rebuild();
    }
    
    ColorTriangle³::ColorTriangle³(const TriangleData<ColorVertex2D>&data, const Param& p) :
        Triangle³(data, p)
    {
        m_color = p.color;
        rebuild();
    }
    
    ColorTriangle³::~ColorTriangle³()
    {
    }

    
    void    ColorTriangle³::rebuild()
    {
        m_vbo   = {
            vs(vertex1()), vs(vertex2()), vs(vertex3())
        };
        m_ubo  = {
            .color  = m_color
        };
    }
    
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::ColorTriangle³)
