////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/rendered/Triangle3.hpp>
#include <tachyon/aspect/AColor.hpp>
#include <tachyon/gfx/UBO.hpp>
#include <tachyon/gfx/VBO.hpp>

namespace yq::tachyon {
    /*! \brief Triangle for three dimensions
    */
    class ColorTriangle³ : public Triangle³, public AColor {
        YQ_TACHYON_DECLARE(ColorTriangle³, Triangle³)
    public:

        struct Param : public Triangle³::Param {
            RGBA4F  color   = kDefColor;

            Param(){}
        };

        static void         init_info();
        
        using AColor::color;
        virtual bool    color(settable_k) const override { return true; }

        ColorTriangle³(const TriangleData<ColorVertex3D>&, const Param& p={});
        ColorTriangle³(const TriangleData<ColorVertex2D>&, const Param& p={});
        ColorTriangle³(const Vertex³&, const Vertex³&, const Vertex³&, const Param&p = {});
        ColorTriangle³(const Param&p = {});
        ~ColorTriangle³();

    protected:
        virtual void    rebuild() override;

        VB1<VertexS>    m_vbo;
        UB1<UBS>        m_ubo;
    };
}

YQ_TACHYON_FORCE(yq::tachyon::ColorTriangle³)

