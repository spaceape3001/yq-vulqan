////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/rendered/ColorTriangle3.hpp>

#include <yq/core/Logging.hpp>
#include <yq/shape/TriangleData.hpp>
#include <yq/shape/shape_utils.hpp>

#include <tachyon/api/Rendered3InfoWriter.hpp>
#include <tachyon/gfx/Shader.hpp>

#include <yq/vector/Vector3.hxx>

namespace yq::tachyon {
    void ColorTriangle³::init_info()
    {
        auto w = writer<ColorTriangle³>();
        w.description("Triangle in 3D");
        w.property("vertex1", &ColorTriangle³::vertex1).setter(&ColorTriangle³::set_vertex1);
        w.property("vertex2", &ColorTriangle³::vertex2).setter(&ColorTriangle³::set_vertex2);
        w.property("vertex3", &ColorTriangle³::vertex3).setter(&ColorTriangle³::set_vertex3);
        w.property("color1", &ColorTriangle³::color1).setter(&ColorTriangle³::set_color1);
        w.property("color2", &ColorTriangle³::color2).setter(&ColorTriangle³::set_color2);
        w.property("color3", &ColorTriangle³::color3).setter(&ColorTriangle³::set_color3);
        
        {
            auto& p = w.pipeline();
            
            p.shader("assets/colored.vert");
            p.shader("assets/colored.frag");

            p.vertex(&ColorTriangle³::m_vertex, DataActivity::FIXED)
                .attribute(&ColorVertexData::position)
                .attribute(&ColorVertexData::color)
            ;
            
            p.push_full();
        }
    }

    ColorTriangle³::ColorTriangle³() : Rendered³({})
    {
        m_vertex    = { 
            ColorVertexData{{-1., -1., 0.}, { 1., 0., 0., 1. }},
            ColorVertexData{{ 1., -1., 0.}, { 0., 1., 0., 1. }},
            ColorVertexData{{ 0.,  1., 0.}, { 0., 0., 1., 1. }}
        };
    }
    
    ColorTriangle³::~ColorTriangle³()
    {
    }

    RGBA4F      ColorTriangle³::color1() const
    {
        return rgba( m_vertex.data[0].color );
    }
    
    RGBA4F      ColorTriangle³::color2() const
    {
        return rgba( m_vertex.data[1].color );
    }
    
    RGBA4F      ColorTriangle³::color3() const
    {
        return rgba( m_vertex.data[2].color );
    }
    
    Execution   ColorTriangle³::tick(const Context&ctx)
    {
        if(dirty())
            m_vertex.update();
        return {};
    }

    void        ColorTriangle³::set_color1(RGBA4F v)
    {
        m_vertex.data[0].color    = v;
        mark();
    }
    
    void        ColorTriangle³::set_color2(RGBA4F v)
    {
        m_vertex.data[1].color    = v;
        mark();
    }
    
    void        ColorTriangle³::set_color3(RGBA4F v)
    {
        m_vertex.data[2].color    = v;
        mark();
    }
    
    void        ColorTriangle³::set_vertex1(Vector3F v)
    {
        m_vertex.data[0].position   = v;
        mark();
    }
    
    void        ColorTriangle³::set_vertex2(Vector3F v)
    {
        m_vertex.data[1].position   = v;
        mark();
    }
    
    void        ColorTriangle³::set_vertex3(Vector3F v)
    {
        m_vertex.data[2].position   = v;
        mark();
    }

    Vector3F    ColorTriangle³::vertex1() const
    {
        return Vector3F(m_vertex.data[0].position);
    }
    
    Vector3F    ColorTriangle³::vertex2() const
    {
        return Vector3F(m_vertex.data[1].position);
    }
    
    Vector3F    ColorTriangle³::vertex3() const
    {
        return Vector3F(m_vertex.data[2].position);
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::ColorTriangle³)
