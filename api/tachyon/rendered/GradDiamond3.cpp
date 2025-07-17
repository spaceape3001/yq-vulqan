////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "GradDiamond3.hpp"

#include <tachyon/tags.hpp>
#include <tachyon/api/Rendered3MetaWriter.hpp>
#include <tachyon/asset/Shader.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::GradDiamond³)

namespace yq::tachyon {
    void GradDiamond³::init_meta()
    {
        auto w = writer<GradDiamond³>();
        w.description("3D Gradient Diamond");
        w.property("east", &GradDiamond³::color_east).setter(&GradDiamond³::set_color_east).tag(kTag_Save);
        w.property("west", &GradDiamond³::color_west).setter(&GradDiamond³::set_color_west).tag(kTag_Save);
        w.property("north", &GradDiamond³::color_north).setter(&GradDiamond³::set_color_north).tag(kTag_Save);
        w.property("south", &GradDiamond³::color_south).setter(&GradDiamond³::set_color_south).tag(kTag_Save);
        w.property("top", &GradDiamond³::color_top).setter(&GradDiamond³::set_color_top).tag(kTag_Save);
        w.property("bottom", &GradDiamond³::color_bottom).setter(&GradDiamond³::set_color_bottom).tag(kTag_Save);
        
        auto& p = w.pipeline();
        p.shader("assets/shape3/gradient.vert");
        p.shader("assets/shape3/gradient.frag");

        p.vertex(&GradDiamond³::m_vbo, DataActivity::DYNAMIC)
            .attribute(&VertexC::position)
            .attribute(&VertexC::color)
        ;

        p.index(s_indices, DataActivity::COMMON);
        p.push_full();
    }

    GradDiamond³::GradDiamond³(const Param& p) : GradDiamond³(kDefSize, p)
    {
    }
    
    GradDiamond³::GradDiamond³(const Size3D&sz, const Param& p) : Diamond³(sz, p)
    {
    }
    
    GradDiamond³::GradDiamond³(const AxBox3D& bx, const Param& p) : Diamond³(bx, p)
    {
    }
    
    GradDiamond³::~GradDiamond³()
    {
    }
    
    void GradDiamond³::set_color_east(const RGBA4F&v)
    {
        vertex_east().color = v;
        mark();
    }
    
    void GradDiamond³::set_color_west(const RGBA4F&v)
    {
        vertex_west().color = v;
        mark();
    }
    
    void GradDiamond³::set_color_north(const RGBA4F&v)
    {
        vertex_north().color = v;
        mark();
    }
    
    void GradDiamond³::set_color_south(const RGBA4F&v)
    {
        vertex_south().color = v;
        mark();
    }
    
    void GradDiamond³::set_color_top(const RGBA4F&v)
    {
        vertex_top().color = v;
        mark();
    }
    
    void GradDiamond³::set_color_bottom(const RGBA4F&v)
    {
        vertex_bottom().color = v;
        mark();
    }
    
    void GradDiamond³::rebuild() 
    {
        Diamond³::rebuild();
        
        m_vbo   = { 
            vc(vertex_east()), vc(vertex_west()), vc(vertex_north()), vc(vertex_south()), 
            vc(vertex_top()), vc(vertex_bottom())
        };
    }
}
