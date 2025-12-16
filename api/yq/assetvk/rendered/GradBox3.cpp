////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "GradBox3.hpp"

#include <yq/tachyon/tags.hpp>
#include <yq/tachyon/api/Rendered3MetaWriter.hpp>
#include <yq/tachyon/asset/Shader.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::GradBox³)

namespace yq::tachyon {
    void GradBox³::init_meta()
    {
        auto w = writer<GradBox³>();
        w.description("3D Gradient Box");
        w.property("bsw", &GradBox³::color_bsw).setter(&GradBox³::set_color_bsw).tag(kTag_Save);
        w.property("bse", &GradBox³::color_bse).setter(&GradBox³::set_color_bse).tag(kTag_Save);
        w.property("bnw", &GradBox³::color_bnw).setter(&GradBox³::set_color_bnw).tag(kTag_Save);
        w.property("bne", &GradBox³::color_bne).setter(&GradBox³::set_color_bne).tag(kTag_Save);
        w.property("tsw", &GradBox³::color_tsw).setter(&GradBox³::set_color_tsw).tag(kTag_Save);
        w.property("tse", &GradBox³::color_tse).setter(&GradBox³::set_color_tse).tag(kTag_Save);
        w.property("tnw", &GradBox³::color_tnw).setter(&GradBox³::set_color_tnw).tag(kTag_Save);
        w.property("tne", &GradBox³::color_tne).setter(&GradBox³::set_color_tne).tag(kTag_Save);
        
        auto& p = w.pipeline();
        p.shader("yq/shape3/gradient.vert");
        p.shader("yq/shape3/gradient.frag");

        p.vertex(&GradBox³::m_vbo, {.activity=DYNAMIC})
            .attribute(&VertexC::position)
            .attribute(&VertexC::color)
        ;

        p.index(s_indices);
        p.push_full();
    }

    GradBox³::GradBox³(const Param& p) : GradBox³(kDefSize, p)
    {
    }
    
    GradBox³::GradBox³(const Size3D&sz, const Param& p) : Box³(sz, p)
    {
    }
    
    GradBox³::~GradBox³()
    {
    }
    
    void GradBox³::set_color_bsw(const RGBA4F&v)
    {
        vertex_bsw().color = v;
        mark();
    }
    
    void GradBox³::set_color_bse(const RGBA4F&v)
    {
        vertex_bse().color = v;
        mark();
    }
    
    void GradBox³::set_color_bnw(const RGBA4F&v)
    {
        vertex_bnw().color = v;
        mark();
    }
    
    void GradBox³::set_color_bne(const RGBA4F&v)
    {
        vertex_bne().color = v;
        mark();
    }
    
    void GradBox³::set_color_tsw(const RGBA4F&v)
    {
        vertex_tsw().color = v;
        mark();
    }
    
    void GradBox³::set_color_tse(const RGBA4F&v)
    {
        vertex_tse().color = v;
        mark();
    }
    
    void GradBox³::set_color_tnw(const RGBA4F&v)
    {
        vertex_tnw().color = v;
        mark();
    }
    
    void GradBox³::set_color_tne(const RGBA4F&v)
    {
        vertex_tne().color = v;
        mark();
    }

    void GradBox³::rebuild() 
    {
        Box³::rebuild();
        
        m_vbo   = { 
            vc(vertex_bsw()), vc(vertex_bse()), vc(vertex_bnw()), vc(vertex_bne()), 
            vc(vertex_tsw()), vc(vertex_tse()), vc(vertex_tnw()), vc(vertex_tne())
        };
    }
}
