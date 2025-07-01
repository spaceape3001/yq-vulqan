////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/rendered/Diamond3.hpp>
#include <tachyon/aspect/AColor.hpp>
#include <tachyon/gfx/UBO.hpp>
#include <tachyon/gfx/VBO.hpp>

namespace yq::tachyon {
    class ColorDiamond³ : public Diamond³, public AColor {
        YQ_TACHYON_DECLARE(ColorDiamond³, Diamond³)
    public:
        using AColor::color;
        virtual bool    color(settable_k) const override { return true; }
        
        struct Param : public Diamond³::Param {
            RGBA4F      color   = kDefColor;
            Param(){}
        };
        
        static void init_meta();
        
        ColorDiamond³(const Param& p={});
        ColorDiamond³(const Size3D&sz, const Param& p={});
        ColorDiamond³(const AxBox3D&, const Param& p={});
        ~ColorDiamond³();
        
    protected:
        
        virtual void rebuild() override;

        VB1<VertexS>    m_vbo;
        UB1<UBS>        m_ubo;
    };
}


YQ_TACHYON_FORCE(yq::tachyon::ColorDiamond³)
