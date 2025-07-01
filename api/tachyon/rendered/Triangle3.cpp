////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Triangle3.hpp"
#include <tachyon/logging.hpp>

#include <yq/color/colors.hpp>
#include <yq/shape/TriangleData.hpp>
#include <yq/shape/shape_utils.hpp>

#include <tachyon/api/Rendered3MetaWriter.hpp>
#include <tachyon/gfx/Shader.hpp>

#include <yq/vector/Vector3.hxx>

#include <tachyon/aspect/AVertices3.hxx>
#include <tachyon/aspect/AVertices3Writer.hxx>

namespace yq::tachyon {
    void Triangle³::init_meta()
    {
        auto w = writer<Triangle³>();
        w.description("Triangle in 3D");
        w.category("Shape");
        w.abstract();

        AVertices³<3>::init_meta(w);

        w.property("vertex1", &Triangle³::vertex1).setter(&Triangle³::set_vertex1);
        w.property("vertex2", &Triangle³::vertex2).setter(&Triangle³::set_vertex2);
        w.property("vertex3", &Triangle³::vertex3).setter(&Triangle³::set_vertex3);

        w.property("point1", &Triangle³::point1).setter(&Triangle³::set_point1).tag({kTag_Save, kTag_Log, kTag_Print});
        w.property("point2", &Triangle³::point2).setter(&Triangle³::set_point2).tag({kTag_Save, kTag_Log, kTag_Print});
        w.property("point3", &Triangle³::point3).setter(&Triangle³::set_point3).tag({kTag_Save, kTag_Log, kTag_Print});

        w.property("x1", &Triangle³::x1);
        w.property("x2", &Triangle³::x2);
        w.property("x3", &Triangle³::x3);

        w.property("y1", &Triangle³::y1);
        w.property("y2", &Triangle³::y2);
        w.property("y3", &Triangle³::y3);

        w.property("z1", &Triangle³::z1);
        w.property("z2", &Triangle³::z2);
        w.property("z3", &Triangle³::z3);

#if 0
        w.property("color1", &Triangle³::color1).setter(&Triangle³::set_color1).tag({kTag_Save, kTag_Log, kTag_Print});
        w.property("color2", &Triangle³::color2).setter(&Triangle³::set_color2).tag({kTag_Save, kTag_Log, kTag_Print});
        w.property("color3", &Triangle³::color3).setter(&Triangle³::set_color3).tag({kTag_Save, kTag_Log, kTag_Print});

        w.property("red1", &Triangle³::red1);
        w.property("red2", &Triangle³::red2);
        w.property("red3", &Triangle³::red3);

        w.property("green1", &Triangle³::green1);
        w.property("green2", &Triangle³::green2);
        w.property("green3", &Triangle³::green3);
        
        w.property("blue1", &Triangle³::blue1);
        w.property("blue2", &Triangle³::blue2);
        w.property("blue3", &Triangle³::blue3);
        
        w.property("alpha1", &Triangle³::alpha1);
        w.property("alpha2", &Triangle³::alpha2);
        w.property("alpha3", &Triangle³::alpha3);

        w.property("uv1", &Triangle³::uv1).setter(&Triangle³::set_uv1).tag({kTag_Save, kTag_Log, kTag_Print});
        w.property("uv2", &Triangle³::uv2).setter(&Triangle³::set_uv2).tag({kTag_Save, kTag_Log, kTag_Print});
        w.property("uv3", &Triangle³::uv3).setter(&Triangle³::set_uv3).tag({kTag_Save, kTag_Log, kTag_Print});

        w.property("u1", &Triangle³::u1);
        w.property("u2", &Triangle³::u2);
        w.property("u3", &Triangle³::u3);

        w.property("v1", &Triangle³::v1);
        w.property("v2", &Triangle³::v2);
        w.property("v3", &Triangle³::v3);

        {
            auto& p = w.pipeline(Pipeline::Role::SolidColor);
            p.shader("assets/shape3/color.vert");
            p.shader("assets/shape3/color.frag");

            p.vertex(&Triangle³::m_vertexS, DataActivity::DYNAMIC)
                .attribute(&VertexS::position)
            ;
            p.uniform(&Triangle³::m_uniformS, DataActivity::DYNAMIC);
            
            p.push_full();
        }


        {
            auto& p = w.pipeline(Pipeline::Role::ColorCorner);
            p.shader("assets/shape3/gradient.vert");
            p.shader("assets/shape3/gradient.frag");

            p.vertex(&Triangle³::m_vertexC, DataActivity::DYNAMIC)
                .attribute(&VertexC::position)
                .attribute(&VertexC::color)
            ;
            
            p.push_full();
        }
#endif
    }
    
    const Vertex³ Triangle³::kDefVertex1{
        .point  = X,
        .uv     = ZERO,
        .color  = (RGBA4F) color::Red
    };

    const Vertex³ Triangle³::kDefVertex2{
        .point  = Y,
        .uv     = U,
        .color  = (RGBA4F) color::Green
    };

    const Vertex³ Triangle³::kDefVertex3{
        .point  = Z,
        .uv     = V,
        .color  = (RGBA4F) color::Blue
    };

    Triangle³::Triangle³(const Param&p) : AbstractShape³(p)
    {
        m_vertices[0] = kDefVertex1;
        m_vertices[1] = kDefVertex2;
        m_vertices[2] = kDefVertex3;
    }

    Triangle³::Triangle³(const Vertex³&a, const Vertex³&b, const Vertex³&c, const Param&p) : 
        AbstractShape³(p)
    {
        m_vertices[0] = a;
        m_vertices[1] = b;
        m_vertices[2] = c;
    }
  
    Triangle³::Triangle³(const TriangleData<ColorVertex3D>&data, const Param& p) : 
        Triangle³(vertex³(data.a), vertex³(data.b), vertex³(data.c), p)
    {
    }
    
    Triangle³::Triangle³(const TriangleData<ColorVertex2D>&data, const Param& p) :
        Triangle³(vertex³(data.a), vertex³(data.b), vertex³(data.c), p)
    {
    }
    
    Triangle³::~Triangle³()
    {
    }

#if 0
    void Triangle³::set_color1(const RGBA4F&v)
    {
        vertex1().color = v;
        mark();
    }
    
    void Triangle³::set_color2(const RGBA4F&v)
    {
        vertex2().color = v;
        mark();
    }
    
    void Triangle³::set_color3(const RGBA4F&v)
    {
        vertex3().color = v;
        mark();
    }
#endif

    void Triangle³::set_point1(const Vector3D& v)
    {
        vertex1().point = v;
        mark();
    }
    
    void Triangle³::set_point2(const Vector3D& v)
    {
        vertex2().point = v;
        mark();
    }
    
    void Triangle³::set_point3(const Vector3D& v)
    {
        vertex3().point = v;
        mark();
    }

#if 0
    void    Triangle³::set_uv1(const UV2F&v)
    {
        vertex1().uv = v;
        mark();
    }
    
    void    Triangle³::set_uv2(const UV2F&v)
    {
        vertex2().uv = v;
        mark();
    }
    
    void    Triangle³::set_uv3(const UV2F&v)
    {
        vertex3().uv = v;
        mark();
    }
#endif

    void    Triangle³::set_vertex1(const Vertex³&v)
    {
        vertex1() = v;
        mark();
    }
    
    void    Triangle³::set_vertex2(const Vertex³&v)
    {
        vertex2() = v;
        mark();
    }
    
    void    Triangle³::set_vertex3(const Vertex³&v)
    {
        vertex3() = v;
        mark();
    }
    
#if 0    

    void    Triangle³::rebuild() 
    {
        switch(draw_mode()){
        case DrawMode::Color:
            rebuild_color();
            break;
        case DrawMode::Gradient:
            rebuild_gradient();
            break;
        case DrawMode::Auto:
        default:
            rebuild_gradient(); // texture will auto-switch....
            break;
        }
    }

    void    Triangle³::rebuild_color()
    {
        set_pipeline(Pipeline::Role::SolidColor);
        m_vertexS   = {
            vs(vertex1()), vs(vertex2()), vs(vertex3())
        };
        m_uniformS  = {
            .color  = m_color
        };
    }
    
    void    Triangle³::rebuild_gradient()
    {
        set_pipeline(Pipeline::Role::ColorCorner);
        m_vertexC = {
            vc(vertex1()), vc(vertex2()), vc(vertex3())
        };
    }
    
    void    Triangle³::rebuild_textured()
    {
        set_pipeline(Pipeline::Role::Textured);
        m_vertexT = {
            vt(vertex1()), vt(vertex2()), vt(vertex3())
        };
    }
#endif

}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Triangle³)
