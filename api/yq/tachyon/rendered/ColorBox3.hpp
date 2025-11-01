////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/rendered/Box3.hpp>
#include <yq/tachyon/aspect/AColor.hpp>
#include <yq/tachyon/pipeline/UBO.hpp>
#include <yq/tachyon/pipeline/VBO.hpp>

namespace yq::tachyon {
    class ColorBox³ : public Box³, public AColor {
        YQ_TACHYON_DECLARE(ColorBox³, Box³)
    public:
        using AColor::color;
        virtual bool    color(settable_k) const override { return true; }
        
        struct Param : public Box³::Param {
            RGBA4F      color   = kDefColor;
            Param(){}
        };
        
        static void init_meta();
        
        ColorBox³(const Param& p={});
        ColorBox³(const Size3D&sz, const Param& p={});
        ColorBox³(const AxBox3D&, const Param& p={});
        ~ColorBox³();
        
    protected:
        
        virtual void rebuild() override;

        VB1<VertexS>    m_vbo;
        UB1<UBS>        m_ubo;
    };
}


YQ_TACHYON_FORCE(yq::tachyon::ColorBox³)
