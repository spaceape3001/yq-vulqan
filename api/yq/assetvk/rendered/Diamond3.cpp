////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Diamond3.hpp"

#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/api/Rendered3MetaWriter.hpp>
#include <yq/tachyon/asset/Shader.hpp>

#include <yq/tachyon/aspect/AVertices3.hxx>
#include <yq/tachyon/aspect/AVertices3Writer.hxx>
#include <yq/tachyon/aspect/ASize3Writer.hxx>

#include <yq/shape/AxBox3.hxx>
#include <yq/shape/Size3.hxx>
#include <yq/vector/Vector3.hxx>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Diamond³);

namespace yq::tachyon {
    
    const uint16_t   Diamond³::s_kIndices[] = { 
        0, 2, 4,            // east-north-top
        2, 1, 4,            // north-west-top
        1, 3, 4,            // west-south-top
        3, 0, 4,            // south-east-top
        0, 3, 5,            // east-south-bottom
        3, 1, 5,            // south-west-bottom
        1, 2, 5,            // west-north-bottom
        2, 0, 5             // north-east-bottom
    };
    IBO<uint16_t>    Diamond³::s_indices(s_kIndices);

    void Diamond³::init_meta()
    {
        auto w = writer<Diamond³>();
        w.description("3D diamond render object");
        MyVertices::init_meta(w);
        
        w.property("point_east", &Diamond³::point_east);
        w.property("point_west", &Diamond³::point_west);
        w.property("point_north", &Diamond³::point_north);
        w.property("point_south", &Diamond³::point_south);
        w.property("point_top", &Diamond³::point_top);
        w.property("point_bottom", &Diamond³::point_bottom);

        w.property("x_east", &Diamond³::x_east);
        w.property("x_west", &Diamond³::x_west);
        w.property("x_north", &Diamond³::x_north);
        w.property("x_south", &Diamond³::x_south);
        w.property("x_top", &Diamond³::x_top);
        w.property("x_bottom", &Diamond³::x_bottom);

        w.property("y_east", &Diamond³::y_east);
        w.property("y_west", &Diamond³::y_west);
        w.property("y_north", &Diamond³::y_north);
        w.property("y_south", &Diamond³::y_south);
        w.property("y_top", &Diamond³::y_top);
        w.property("y_bottom", &Diamond³::y_bottom);

        w.property("z_east", &Diamond³::z_east);
        w.property("z_west", &Diamond³::z_west);
        w.property("z_north", &Diamond³::z_north);
        w.property("z_south", &Diamond³::z_south);
        w.property("z_top", &Diamond³::z_top);
        w.property("z_bottom", &Diamond³::z_bottom);

        w.property("color_east", &Diamond³::color_east).setter(&Diamond³::set_color_east).tag({kTag_Save, kTag_Log, kTag_Print});
        w.property("color_west", &Diamond³::color_west).setter(&Diamond³::set_color_west).tag({kTag_Save, kTag_Log, kTag_Print});
        w.property("color_north", &Diamond³::color_north).setter(&Diamond³::set_color_north).tag({kTag_Save, kTag_Log, kTag_Print});
        w.property("color_south", &Diamond³::color_south).setter(&Diamond³::set_color_south).tag({kTag_Save, kTag_Log, kTag_Print});
        w.property("color_top", &Diamond³::color_top).setter(&Diamond³::set_color_top).tag({kTag_Save, kTag_Log, kTag_Print});
        w.property("color_bottom", &Diamond³::color_bottom).setter(&Diamond³::set_color_bottom).tag({kTag_Save, kTag_Log, kTag_Print});

        w.property("red_east", &Diamond³::red_east);
        w.property("red_west", &Diamond³::red_west);
        w.property("red_north", &Diamond³::red_north);
        w.property("red_south", &Diamond³::red_south);
        w.property("red_top", &Diamond³::red_top);
        w.property("red_bottom", &Diamond³::red_bottom);

        w.property("green_east", &Diamond³::green_east);
        w.property("green_west", &Diamond³::green_west);
        w.property("green_north", &Diamond³::green_north);
        w.property("green_south", &Diamond³::green_south);
        w.property("green_top", &Diamond³::green_top);
        w.property("green_bottom", &Diamond³::green_bottom);
        
        w.property("blue_east", &Diamond³::blue_east);
        w.property("blue_west", &Diamond³::blue_west);
        w.property("blue_north", &Diamond³::blue_north);
        w.property("blue_south", &Diamond³::blue_south);
        w.property("blue_top", &Diamond³::blue_top);
        w.property("blue_bottom", &Diamond³::blue_bottom);
        
        w.property("alpha_east", &Diamond³::alpha_east);
        w.property("alpha_west", &Diamond³::alpha_west);
        w.property("alpha_north", &Diamond³::alpha_north);
        w.property("alpha_south", &Diamond³::alpha_south);
        w.property("alpha_top", &Diamond³::alpha_top);
        w.property("alpha_bottom", &Diamond³::alpha_bottom);

        w.property("uv_east", &Diamond³::uv_east).setter(&Diamond³::set_uv_east).tag({kTag_Save, kTag_Log, kTag_Print});
        w.property("uv_west", &Diamond³::uv_west).setter(&Diamond³::set_uv_west).tag({kTag_Save, kTag_Log, kTag_Print});
        w.property("uv_north", &Diamond³::uv_north).setter(&Diamond³::set_uv_north).tag({kTag_Save, kTag_Log, kTag_Print});
        w.property("uv_south", &Diamond³::uv_south).setter(&Diamond³::set_uv_south).tag({kTag_Save, kTag_Log, kTag_Print});
        w.property("uv_top", &Diamond³::uv_top).setter(&Diamond³::set_uv_top).tag({kTag_Save, kTag_Log, kTag_Print});
        w.property("uv_bottom", &Diamond³::uv_bottom).setter(&Diamond³::set_uv_bottom).tag({kTag_Save, kTag_Log, kTag_Print});

        w.property("u_east", &Diamond³::u_east);
        w.property("u_west", &Diamond³::u_west);
        w.property("u_north", &Diamond³::u_north);
        w.property("u_south", &Diamond³::u_south);
        w.property("u_top", &Diamond³::u_top);
        w.property("u_bottom", &Diamond³::u_bottom);

        w.property("v_east", &Diamond³::v_east);
        w.property("v_west", &Diamond³::v_west);
        w.property("v_north", &Diamond³::v_north);
        w.property("v_south", &Diamond³::v_south);
        w.property("v_top", &Diamond³::v_top);
        w.property("v_bottom", &Diamond³::v_bottom);


        {
            auto& p = w.pipeline(Pipeline::Role::SolidColor);
            
            p.shader("yq/shape3/color.vert");
            p.shader("yq/shape3/color.frag");

            p.vertex(&Diamond³::m_vertexS, {.activity=DYNAMIC})
                .attribute(&VertexS::position)
            ;

            p.uniform(&Diamond³::m_uniformS, {.activity=DYNAMIC});
            p.index(Diamond³::s_indices);
            p.push_full();
        }

        {
            auto& p = w.pipeline(Pipeline::Role::ColorCorner);
            
            p.shader("yq/shape3/gradient.vert");
            p.shader("yq/shape3/gradient.frag");

            p.vertex(&Diamond³::m_vertexC, {.activity=DYNAMIC})
                .attribute(&VertexC::position)
                .attribute(&VertexC::color)
            ;

            //p.uniform(_uniformS(), DataActivity::DYNAMIC);
            p.index(Diamond³::s_indices);
            p.push_full();
        }
    }

    Diamond³::Diamond³() : Diamond³(Param())
    {
    }

    Diamond³::Diamond³(const Param& p) : Shape³(p)
    {
        reshape();
    }

    Diamond³::~Diamond³()
    {
    }


    DrawMode    Diamond³::draw_mode(use_k) const
    {
        switch(m_drawMode){
        case DrawMode::Auto:
            return DrawMode::Color;
        default:    
            return m_drawMode;
        }
    }
    
    void    Diamond³::rebuild() 
    {
        Shape³::rebuild();
        switch(draw_mode(USE)){
        case DrawMode::Color:
            m_good      = true;
            set_pipeline(Pipeline::Role::SolidColor);
            m_vertexS   = {
                vs(vertex_east()), vs(vertex_west()), vs(vertex_north()), vs(vertex_south()), 
                vs(vertex_top()), vs(vertex_bottom())
            };
            m_uniformS  = {
                .color  = m_color
            };
            break;
        case DrawMode::Gradient:
            m_good      = true;
            set_pipeline(Pipeline::Role::ColorCorner);
            m_vertexC = {
                vc(vertex_east()), vc(vertex_west()), vc(vertex_north()), vc(vertex_south()), 
                vc(vertex_top()), vc(vertex_bottom())
            };
            break;
        default:
            m_good      = false;
            // shouldn't happen...
            break;
        }
    }

    void    Diamond³::reshape()
    {
        vertex_east().point     = { -1.,  0.,  0. };
        vertex_west().point     = {  1.,  0.,  0. };
        vertex_north().point    = {  0.,  1.,  0. };
        vertex_south().point    = {  0., -1.,  0. };
        vertex_top().point      = {  0.,  0.,  1. };
        vertex_bottom().point   = {  0.,  0., -1. };
    }

    void Diamond³::set_color_east(const RGBA4F&v)
    {
        vertex_east().color = v;
        mark();
    }
    
    void Diamond³::set_color_west(const RGBA4F&v)
    {
        vertex_west().color = v;
        mark();
    }
    
    void Diamond³::set_color_north(const RGBA4F&v)
    {
        vertex_north().color = v;
        mark();
    }

    void Diamond³::set_color_south(const RGBA4F&v)
    {
        vertex_south().color = v;
        mark();
    }

    void Diamond³::set_color_top(const RGBA4F&v)
    {
        vertex_top().color = v;
        mark();
    }

    void Diamond³::set_color_bottom(const RGBA4F&v)
    {
        vertex_bottom().color = v;
        mark();
    }

    void    Diamond³::set_uv_east(const UV2F&v)
    {
        vertex_east().uv = v;
        mark();
    }
    
    void    Diamond³::set_uv_west(const UV2F&v)
    {
        vertex_west().uv = v;
        mark();
    }
    
    void    Diamond³::set_uv_north(const UV2F&v)
    {
        vertex_north().uv = v;
        mark();
    }

    void    Diamond³::set_uv_south(const UV2F&v)
    {
        vertex_south().uv = v;
        mark();
    }

    void    Diamond³::set_uv_top(const UV2F&v)
    {
        vertex_top().uv = v;
        mark();
    }

    void    Diamond³::set_uv_bottom(const UV2F&v)
    {
        vertex_bottom().uv = v;
        mark();
    }


    bool    Diamond³::vertices(color_k) const
    {
        switch(draw_mode(USE)){
        case DrawMode::Gradient:
            return true;
        default:    
            return false;
        }
    }
}
