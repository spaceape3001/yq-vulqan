////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Tetrahedron3.hpp"
#include <tachyon/logging.hpp>

#include <yq/color/colors.hpp>
#include <yq/shape/TetrahedronData.hpp>
#include <yq/shape/shape_utils.hpp>

#include <tachyon/gfx/Shader.hpp>
#include <tachyon/api/Rendered3InfoWriter.hpp>

#include <yq/vector/Vector3.hxx>
#include <tachyon/aspect/AVertices3.hxx>
#include <tachyon/aspect/AVertices3Writer.hxx>

#include <tachyon/gfx/Texture.hpp>

namespace yq::tachyon {
    const Vertex³ Tetrahedron³::kDefVertex1{
        .point  = ZERO,
        .uv     = ZERO,
        .color  = (RGBA4F) color::White
    };

    const Vertex³ Tetrahedron³::kDefVertex2{
        .point  = X,
        .uv     = U,
        .color  = (RGBA4F) color::Red
    };

    const Vertex³ Tetrahedron³::kDefVertex3{
        .point  = Y,
        .uv     = V,
        .color  = (RGBA4F) color::Green
    };

    const Vertex³ Tetrahedron³::kDefVertex4{
        .point  = Z,
        .uv     = { 1., 1. },
        .color  = (RGBA4F) color::Blue
    };

    const uint16_t   Tetrahedron³::s_kIndices[] = { 1, 2, 3, 0, 3, 2, 0, 1, 3, 0, 2, 1 };
    IBO<uint16_t>    Tetrahedron³::s_indices(s_kIndices);


    void Tetrahedron³::init_info()
    {
        auto w = writer<Tetrahedron³>();
        w.description("Tetrahedron in 3D");
        w.category("Shape");
        w.abstract();

        AVertices³<4>::init_info(w);

        w.property("vertex1", &Tetrahedron³::vertex1).setter(&Tetrahedron³::set_vertex1);
        w.property("vertex2", &Tetrahedron³::vertex2).setter(&Tetrahedron³::set_vertex2);
        w.property("vertex3", &Tetrahedron³::vertex3).setter(&Tetrahedron³::set_vertex3);
        w.property("vertex4", &Tetrahedron³::vertex4).setter(&Tetrahedron³::set_vertex4);

        w.property("point1", &Tetrahedron³::point1).setter(&Tetrahedron³::set_point1).tag({kTag_Save, kTag_Log, kTag_Print});
        w.property("point2", &Tetrahedron³::point2).setter(&Tetrahedron³::set_point2).tag({kTag_Save, kTag_Log, kTag_Print});
        w.property("point3", &Tetrahedron³::point3).setter(&Tetrahedron³::set_point3).tag({kTag_Save, kTag_Log, kTag_Print});
        w.property("point4", &Tetrahedron³::point4).setter(&Tetrahedron³::set_point4).tag({kTag_Save, kTag_Log, kTag_Print});

        w.property("x1", &Tetrahedron³::x1);
        w.property("x2", &Tetrahedron³::x2);
        w.property("x3", &Tetrahedron³::x3);
        w.property("x4", &Tetrahedron³::x4);

        w.property("y1", &Tetrahedron³::y1);
        w.property("y2", &Tetrahedron³::y2);
        w.property("y3", &Tetrahedron³::y3);
        w.property("y4", &Tetrahedron³::y4);

        w.property("z1", &Tetrahedron³::z1);
        w.property("z2", &Tetrahedron³::z2);
        w.property("z3", &Tetrahedron³::z3);
        w.property("z4", &Tetrahedron³::z4);

#if 0
        w.property("color1", &Tetrahedron³::color1).setter(&Tetrahedron³::set_color1).tag({kTag_Save, kTag_Log, kTag_Print});
        w.property("color2", &Tetrahedron³::color2).setter(&Tetrahedron³::set_color2).tag({kTag_Save, kTag_Log, kTag_Print});
        w.property("color3", &Tetrahedron³::color3).setter(&Tetrahedron³::set_color3).tag({kTag_Save, kTag_Log, kTag_Print});
        w.property("color4", &Tetrahedron³::color4).setter(&Tetrahedron³::set_color4).tag({kTag_Save, kTag_Log, kTag_Print});

        w.property("red1", &Tetrahedron³::red1);
        w.property("red2", &Tetrahedron³::red2);
        w.property("red3", &Tetrahedron³::red3);
        w.property("red4", &Tetrahedron³::red4);

        w.property("green1", &Tetrahedron³::green1);
        w.property("green2", &Tetrahedron³::green2);
        w.property("green3", &Tetrahedron³::green3);
        w.property("green4", &Tetrahedron³::green4);
        
        w.property("blue1", &Tetrahedron³::blue1);
        w.property("blue2", &Tetrahedron³::blue2);
        w.property("blue3", &Tetrahedron³::blue3);
        w.property("blue4", &Tetrahedron³::blue4);
        
        w.property("alpha1", &Tetrahedron³::alpha1);
        w.property("alpha2", &Tetrahedron³::alpha2);
        w.property("alpha3", &Tetrahedron³::alpha3);
        w.property("alpha4", &Tetrahedron³::alpha4);

        w.property("uv1", &Tetrahedron³::uv1).setter(&Tetrahedron³::set_uv1).tag({kTag_Save, kTag_Log, kTag_Print});
        w.property("uv2", &Tetrahedron³::uv2).setter(&Tetrahedron³::set_uv2).tag({kTag_Save, kTag_Log, kTag_Print});
        w.property("uv3", &Tetrahedron³::uv3).setter(&Tetrahedron³::set_uv3).tag({kTag_Save, kTag_Log, kTag_Print});
        w.property("uv4", &Tetrahedron³::uv4).setter(&Tetrahedron³::set_uv4).tag({kTag_Save, kTag_Log, kTag_Print});

        w.property("u1", &Tetrahedron³::u1);
        w.property("u2", &Tetrahedron³::u2);
        w.property("u3", &Tetrahedron³::u3);
        w.property("u4", &Tetrahedron³::u4);

        w.property("v1", &Tetrahedron³::v1);
        w.property("v2", &Tetrahedron³::v2);
        w.property("v3", &Tetrahedron³::v3);
        w.property("v4", &Tetrahedron³::v4);
#endif

#if 0
        {
            auto& p = w.pipeline(Pipeline::Role::SolidColor);
            
            p.shader("assets/shape3/color.vert");
            p.shader("assets/shape3/color.frag");

            p.vertex(&Tetrahedron³::m_vertexS, DataActivity::DYNAMIC)
                .attribute(&VertexS::position)
            ;

            p.uniform(&Tetrahedron³::m_uniformS, DataActivity::DYNAMIC);
            p.index(Tetrahedron³::s_indices, DataActivity::COMMON);
            p.push_full();
        }

        {
            auto& p = w.pipeline(Pipeline::Role::ColorCorner);
            
            p.shader("assets/shape3/gradient.vert");
            p.shader("assets/shape3/gradient.frag");

            p.vertex(&Tetrahedron³::m_vertexC, DataActivity::DYNAMIC)
                .attribute(&VertexC::position)
                .attribute(&VertexC::color)
            ;

            //p.uniform(_uniformS(), DataActivity::DYNAMIC);
            p.index(Tetrahedron³::s_indices, DataActivity::COMMON);
            p.push_full();
        }
#endif
    }

    Tetrahedron³::Tetrahedron³(const Vertex³&a, const Vertex³&b, const Vertex³&c, const Vertex³&d, const Param&p) : 
        AbstractShape³(p)
    {
        m_vertices[0] = a;
        m_vertices[1] = b;
        m_vertices[2] = c;
        m_vertices[3] = d;
    }
  
    Tetrahedron³::Tetrahedron³(const TetrahedronData<ColorVertex3D>&data, const Param& p) : 
        Tetrahedron³(vertex³(data.a), vertex³(data.b), vertex³(data.c), vertex³(data.d), p)
    {
    }

    Tetrahedron³::Tetrahedron³(const Param&p) : Tetrahedron³(kDefVertex1, kDefVertex2, kDefVertex3, kDefVertex4, p)
    {
    }

    Tetrahedron³::~Tetrahedron³()
    {
    }

#if 0
    DrawMode Tetrahedron³::draw_mode(use_k) const 
    {
        //  get smarter.... (later)
        DrawMode    dm  = draw_mode();
        switch(dm){
        case DrawMode::Auto:
            return DrawMode::Gradient;
        default:
            return dm;
        }
    }
#endif

#if 0
    void Tetrahedron³::set_color1(const RGBA4F&v)
    {
        vertex1().color = v;
        mark();
    }
    
    void Tetrahedron³::set_color2(const RGBA4F&v)
    {
        vertex2().color = v;
        mark();
    }
    
    void Tetrahedron³::set_color3(const RGBA4F&v)
    {
        vertex3().color = v;
        mark();
    }

    void Tetrahedron³::set_color4(const RGBA4F&v)
    {
        vertex4().color = v;
        mark();
    }
#endif

    void Tetrahedron³::set_point1(const Vector3D& v)
    {
        vertex1().point = v;
        mark();
    }
    
    void Tetrahedron³::set_point2(const Vector3D& v)
    {
        vertex2().point = v;
        mark();
    }
    
    void Tetrahedron³::set_point3(const Vector3D& v)
    {
        vertex3().point = v;
        mark();
    }

    void Tetrahedron³::set_point4(const Vector3D& v)
    {
        vertex4().point = v;
        mark();
    }

#if 0
    void    Tetrahedron³::set_uv1(const UV2F&v)
    {
        vertex1().uv = v;
        mark();
    }
    
    void    Tetrahedron³::set_uv2(const UV2F&v)
    {
        vertex2().uv = v;
        mark();
    }
    
    void    Tetrahedron³::set_uv3(const UV2F&v)
    {
        vertex3().uv = v;
        mark();
    }

    void    Tetrahedron³::set_uv4(const UV2F&v)
    {
        vertex4().uv = v;
        mark();
    }
#endif

    void    Tetrahedron³::set_vertex1(const Vertex³&v)
    {
        vertex1() = v;
        mark();
    }
    
    void    Tetrahedron³::set_vertex2(const Vertex³&v)
    {
        vertex2() = v;
        mark();
    }
    
    void    Tetrahedron³::set_vertex3(const Vertex³&v)
    {
        vertex3() = v;
        mark();
    }

    void    Tetrahedron³::set_vertex4(const Vertex³&v)
    {
        vertex4() = v;
        mark();
    }

#if 0
    void    Tetrahedron³::rebuild() 
    {
        switch(draw_mode(USE)){
        case DrawMode::Color:
            rebuild_color();
            break;
        case DrawMode::Gradient:
            rebuild_gradient();
            break;
        default:
            // shouldn't happen...
            break;
        }
    }

    void    Tetrahedron³::rebuild_color()
    {
        set_pipeline(Pipeline::Role::SolidColor);
        m_vertexS   = {
            vs(vertex1()), vs(vertex2()), vs(vertex3()), vs(vertex4())
        };
        m_uniformS  = {
            .color  = m_color
        };
    }
    
    void    Tetrahedron³::rebuild_gradient()
    {
        set_pipeline(Pipeline::Role::ColorCorner);
        m_vertexC = {
            vc(vertex1()), vc(vertex2()), vc(vertex3()), vc(vertex4())
        };
    }
    
    void    Tetrahedron³::rebuild_textured()
    {
        set_pipeline(Pipeline::Role::Textured);
        m_vertexT = {
            vt(vertex1()), vt(vertex2()), vt(vertex3()), vt(vertex4())
        };
    }
#endif
#if 0
    bool    Tetrahedron³::vertices(color_k) const
    {
        switch(draw_mode(USE)){
        case DrawMode::Color:
            return true;
        default:    
            return false;
        }
    }
#endif
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Tetrahedron³)
