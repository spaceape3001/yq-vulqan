////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ColorTriangle3.hpp"
#include <tachyon/logging.hpp>
#include <tachyon/api/Rendered3InfoWriter.hpp>
#include <tachyon/gfx/Shader.hpp>
#include <yq/vector/Vector3.hxx>
#include <tachyon/aspect/AColorWriter.hxx>

namespace yq::tachyon {
    void ColorTriangle³::init_info()
    {
        auto w = writer<ColorTriangle³>();
        w.description("Color Triangle in 3D");
        w.category("Shape");

        AColor::init_info(w);

        auto& p = w.pipeline();
        p.shader("assets/shape3/color.vert");
        p.shader("assets/shape3/color.frag");

        p.vertex(&ColorTriangle³::m_vbo, DataActivity::DYNAMIC)
            .attribute(&VertexS::position)
        ;
        p.uniform(&ColorTriangle³::m_ubo, DataActivity::DYNAMIC);
        
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
