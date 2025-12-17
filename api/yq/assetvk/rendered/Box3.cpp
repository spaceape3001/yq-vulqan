////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Box3.hpp"

#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/api/Rendered3MetaWriter.hpp>
#include <yq/tachyon/asset/Shader.hpp>

#include <yq/tachyon/aspect/AVertices3.hxx>
#include <yq/tachyon/aspect/AVertices3Writer.hxx>

#include <yq/shape/AxBox3.hxx>
#include <yq/shape/Size3.hxx>
#include <yq/vector/Vector3.hxx>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Box³);

namespace yq::tachyon {
    
    const uint16_t   Box³::s_kIndices[] = { 
        0, 2, 3, 0, 3, 1,   // bottom face
        4, 5, 7, 7, 6, 4,   // top face
        0, 1, 5, 5, 4, 0,   // south face
        2, 0, 6, 0, 4, 6,   // west face,
        2, 7, 3, 6, 7, 2,   // north face
        3, 7, 5, 5, 1, 3    // east face
    };
    IBO<uint16_t>    Box³::s_indices(s_kIndices);

    void Box³::init_meta()
    {
        auto w = writer<Box³>();
        w.description("3D Box render object");
        MyVertices::init_meta(w);
        
        w.property("point_bsw", &Box³::point_bsw);
        w.property("point_bse", &Box³::point_bse);
        w.property("point_bnw", &Box³::point_bnw);
        w.property("point_bne", &Box³::point_bne);
        w.property("point_tsw", &Box³::point_tsw);
        w.property("point_tse", &Box³::point_tse);
        w.property("point_tnw", &Box³::point_tnw);
        w.property("point_tne", &Box³::point_tne);

        w.property("x_bsw", &Box³::x_bsw);
        w.property("x_bse", &Box³::x_bse);
        w.property("x_bnw", &Box³::x_bnw);
        w.property("x_bne", &Box³::x_bne);
        w.property("x_tsw", &Box³::x_tsw);
        w.property("x_tse", &Box³::x_tse);
        w.property("x_tnw", &Box³::x_tnw);
        w.property("x_tne", &Box³::x_tne);

        w.property("y_bsw", &Box³::y_bsw);
        w.property("y_bse", &Box³::y_bse);
        w.property("y_bnw", &Box³::y_bnw);
        w.property("y_bne", &Box³::y_bne);
        w.property("y_tsw", &Box³::y_tsw);
        w.property("y_tse", &Box³::y_tse);
        w.property("y_tnw", &Box³::y_tnw);
        w.property("y_tne", &Box³::y_tne);

        w.property("z_bsw", &Box³::z_bsw);
        w.property("z_bse", &Box³::z_bse);
        w.property("z_bnw", &Box³::z_bnw);
        w.property("z_bne", &Box³::z_bne);
        w.property("z_tsw", &Box³::z_tsw);
        w.property("z_tse", &Box³::z_tse);
        w.property("z_tnw", &Box³::z_tnw);
        w.property("z_tne", &Box³::z_tne);

        w.property("color_bsw", &Box³::color_bsw).setter(&Box³::set_color_bsw).tag(kTag_Save);
        w.property("color_bse", &Box³::color_bse).setter(&Box³::set_color_bse).tag(kTag_Save);
        w.property("color_bnw", &Box³::color_bnw).setter(&Box³::set_color_bnw).tag(kTag_Save);
        w.property("color_bne", &Box³::color_bne).setter(&Box³::set_color_bne).tag(kTag_Save);
        w.property("color_tsw", &Box³::color_tsw).setter(&Box³::set_color_tsw).tag(kTag_Save);
        w.property("color_tse", &Box³::color_tse).setter(&Box³::set_color_tse).tag(kTag_Save);
        w.property("color_tnw", &Box³::color_tnw).setter(&Box³::set_color_tnw).tag(kTag_Save);
        w.property("color_tne", &Box³::color_tne).setter(&Box³::set_color_tne).tag(kTag_Save);
     
        {
            auto& p = w.pipeline(Pipeline::Role::SolidColor);
            p.shader("yq/shape3/color.vert");
            p.shader("yq/shape3/color.frag");

            p.vertex(&Box³::m_vertexS, {.activity=DYNAMIC})
                .attribute(&VertexS::position)
            ;

            p.uniform(&Box³::m_uniformS, {.activity=DYNAMIC});
            p.index(s_indices);
            p.push_full();
        }
     
        {
            auto& p = w.pipeline(Pipeline::Role::ColorCorner);
            p.shader("yq/shape3/gradient.vert");
            p.shader("yq/shape3/gradient.frag");

            p.vertex(&Box³::m_vertexC, {.activity=DYNAMIC})
                .attribute(&VertexC::position)
                .attribute(&VertexC::color)
            ;

            p.index(s_indices);
            p.push_full();
        }
    }

    Box³::Box³() : Box³(Param())
    {
    }

    Box³::Box³(const Param& p) : Shape³(p)
    {
        reshape();
    }

    Box³::~Box³()
    {
    }

    DrawMode    Box³::draw_mode(use_k) const
    {
        switch(m_drawMode){
        case DrawMode::Auto:
            return DrawMode::Color;
        default:    
            return m_drawMode;
        }
    }

    void    Box³::rebuild() 
    {
        Shape³::rebuild();
        switch(draw_mode(USE)){
        case DrawMode::Color:
            m_good      = true;
            set_pipeline(Pipeline::Role::SolidColor);
            m_vertexS   = {
            vs(vertex_bsw()), vs(vertex_bse()), vs(vertex_bnw()), vs(vertex_bne()), 
            vs(vertex_tsw()), vs(vertex_tse()), vs(vertex_tnw()), vs(vertex_tne())
            };
            m_uniformS  = {
                .color  = m_color
            };
            break;
        case DrawMode::Gradient:
            m_good      = true;
            set_pipeline(Pipeline::Role::ColorCorner);
            m_vertexC = {
                vc(vertex_bsw()), vc(vertex_bse()), vc(vertex_bnw()), vc(vertex_bne()), 
                vc(vertex_tsw()), vc(vertex_tse()), vc(vertex_tnw()), vc(vertex_tne())
            };
            break;
        default:
            m_good      = false;
            // shouldn't happen...
            break;
        }
    }

    void    Box³::reshape()
    {
        vertex_bsw().point  = { -1.0, -1.0, -1.0 };
        vertex_bse().point  = {  1.0, -1.0, -1.0 };
        vertex_bnw().point  = { -1.0,  1.0, -1.0 };
        vertex_bne().point  = {  1.0,  1.0, -1.0 };
        vertex_tsw().point  = { -1.0, -1.0,  1.0 };
        vertex_tse().point  = {  1.0, -1.0,  1.0 };
        vertex_tnw().point  = { -1.0,  1.0,  1.0 };
        vertex_tne().point  = {  1.0,  1.0,  1.0 };
    }


    void Box³::set_color_bsw(const RGBA4F&v)
    {
        vertex_bsw().color = v;
        mark();
    }
    
    void Box³::set_color_bse(const RGBA4F&v)
    {
        vertex_bse().color = v;
        mark();
    }
    
    void Box³::set_color_bnw(const RGBA4F&v)
    {
        vertex_bnw().color = v;
        mark();
    }
    
    void Box³::set_color_bne(const RGBA4F&v)
    {
        vertex_bne().color = v;
        mark();
    }
    
    void Box³::set_color_tsw(const RGBA4F&v)
    {
        vertex_tsw().color = v;
        mark();
    }
    
    void Box³::set_color_tse(const RGBA4F&v)
    {
        vertex_tse().color = v;
        mark();
    }
    
    void Box³::set_color_tnw(const RGBA4F&v)
    {
        vertex_tnw().color = v;
        mark();
    }
    
    void Box³::set_color_tne(const RGBA4F&v)
    {
        vertex_tne().color = v;
        mark();
    }
    
    bool    Box³::vertices(color_k) const
    {
        switch(draw_mode(USE)){
        case DrawMode::Gradient:
            return true;
        default:    
            return false;
        }
    }
}
