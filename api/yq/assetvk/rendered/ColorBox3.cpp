////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ColorBox3.hpp"
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/aspect/AColor.hpp>
#include <yq/tachyon/api/Rendered3MetaWriter.hpp>
#include <yq/tachyon/asset/Shader.hpp>
#include <yq/tachyon/aspect/AColorWriter.hxx>


YQ_TACHYON_IMPLEMENT(yq::tachyon::ColorBox³)

namespace yq::tachyon {
    void ColorBox³::init_meta()
    {
        auto w = writer<ColorBox³>();
        w.description("Simple 3D Color Box");
        AColor::init_meta(w);
        
        auto& p = w.pipeline();
        p.shader("yq/shape3/color.vert");
        p.shader("yq/shape3/color.frag");

        p.vertex(&ColorBox³::m_vbo, {.activity=DYNAMIC})
            .attribute(&VertexS::position)
        ;

        p.uniform(&ColorBox³::m_ubo, {.activity=DYNAMIC});
        p.index(s_indices);
        p.push_full();
    }

    ColorBox³::ColorBox³(const Param& p) : ColorBox³(kDefSize, p)
    {
    }

    ColorBox³::ColorBox³(const Size3D&sz, const Param& p) : Box³(sz, p)
    {
        m_color = p.color;
    }
    
    ColorBox³::~ColorBox³()
    {
    }

    void ColorBox³::rebuild() 
    {
        Box³::rebuild();
        
        m_vbo   = { 
            vs(vertex_bsw()), vs(vertex_bse()), vs(vertex_bnw()), vs(vertex_bne()), 
            vs(vertex_tsw()), vs(vertex_tse()), vs(vertex_tnw()), vs(vertex_tne())
        };
        
        m_ubo   = {
            .color  = m_color
        };
    }
}

