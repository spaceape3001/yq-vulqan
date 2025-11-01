////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ColorDiamond3.hpp"
#include <tachyon/logging.hpp>
#include <tachyon/aspect/AColor.hpp>
#include <tachyon/api/Rendered3MetaWriter.hpp>
#include <tachyon/asset/Shader.hpp>
#include <tachyon/aspect/AColorWriter.hxx>


YQ_TACHYON_IMPLEMENT(yq::tachyon::ColorDiamond³)

namespace yq::tachyon {
    void ColorDiamond³::init_meta()
    {
        auto w = writer<ColorDiamond³>();
        w.description("Simple 3D Color Diamond");
        AColor::init_meta(w);
        
        auto& p = w.pipeline();
        p.shader("resources/shape3/color.vert");
        p.shader("resources/shape3/color.frag");

        p.vertex(&ColorDiamond³::m_vbo, DataActivity::DYNAMIC)
            .attribute(&VertexS::position)
        ;

        p.uniform(&ColorDiamond³::m_ubo, DataActivity::DYNAMIC);
        p.index(s_indices, DataActivity::COMMON);
        p.push_full();
    }

    ColorDiamond³::ColorDiamond³(const Param& p) : ColorDiamond³(kDefSize, p)
    {
    }

    ColorDiamond³::ColorDiamond³(const Size3D&sz, const Param& p) : Diamond³(sz, p)
    {
        m_color = p.color;
    }
    
    ColorDiamond³::ColorDiamond³(const AxBox3D&bx, const Param& p) : Diamond³(bx, p)
    {
        m_color = p.color;
    }
    
    ColorDiamond³::~ColorDiamond³()
    {
    }

    void ColorDiamond³::rebuild() 
    {
        Diamond³::rebuild();
        
        m_vbo   = { 
            vs(vertex_east()), vs(vertex_west()), vs(vertex_north()), vs(vertex_south()), 
            vs(vertex_top()), vs(vertex_bottom())
        };
        
        m_ubo   = {
            .color  = m_color
        };
    }
}

