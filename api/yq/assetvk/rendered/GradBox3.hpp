////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/assetvk/rendered/Box3.hpp>
#include <yq/tachyon/pipeline/VBO.hpp>

namespace yq::tachyon {
    class GradBox³ : public Box³ {
        YQ_TACHYON_DECLARE(GradBox³, Box³)
    public:
    
        static void init_meta();
        
        GradBox³(const Param& p={});
        GradBox³(const Size3D&sz, const Param& p={});
        ~GradBox³();

        using MyVertices::vertices;
        virtual bool        vertices(color_k) const { return true; }

        const RGBA4F& color_bsw() const { return vertex_bsw().color; }
        const RGBA4F& color_bse() const { return vertex_bse().color; }
        const RGBA4F& color_bnw() const { return vertex_bnw().color; }
        const RGBA4F& color_bne() const { return vertex_bne().color; }
        const RGBA4F& color_tsw() const { return vertex_tsw().color; }
        const RGBA4F& color_tse() const { return vertex_tse().color; }
        const RGBA4F& color_tnw() const { return vertex_tnw().color; }
        const RGBA4F& color_tne() const { return vertex_tne().color; }

        float   red_bsw() const { return color_bsw().red; }
        float   red_bse() const { return color_bse().red; }
        float   red_bnw() const { return color_bnw().red; }
        float   red_bne() const { return color_bne().red; }
        float   red_tsw() const { return color_tsw().red; }
        float   red_tse() const { return color_tse().red; }
        float   red_tnw() const { return color_tnw().red; }
        float   red_tne() const { return color_tne().red; }
        
        float   green_bsw() const { return color_bsw().green; }
        float   green_bse() const { return color_bse().green; }
        float   green_bnw() const { return color_bnw().green; }
        float   green_bne() const { return color_bne().green; }
        float   green_tsw() const { return color_tsw().green; }
        float   green_tse() const { return color_tse().green; }
        float   green_tnw() const { return color_tnw().green; }
        float   green_tne() const { return color_tne().green; }

        float   blue_bsw() const { return color_bsw().blue; }
        float   blue_bse() const { return color_bse().blue; }
        float   blue_bnw() const { return color_bnw().blue; }
        float   blue_bne() const { return color_bne().blue; }
        float   blue_tsw() const { return color_tsw().blue; }
        float   blue_tse() const { return color_tse().blue; }
        float   blue_tnw() const { return color_tnw().blue; }
        float   blue_tne() const { return color_tne().blue; }

        float   alpha_bsw() const { return color_bsw().alpha; }
        float   alpha_bse() const { return color_bse().alpha; }
        float   alpha_bnw() const { return color_bnw().alpha; }
        float   alpha_bne() const { return color_bne().alpha; }
        float   alpha_tsw() const { return color_tsw().alpha; }
        float   alpha_tse() const { return color_tse().alpha; }
        float   alpha_tnw() const { return color_tnw().alpha; }
        float   alpha_tne() const { return color_tne().alpha; }
        
        void    set_color_bsw(const RGBA4F&);
        void    set_color_bse(const RGBA4F&);
        void    set_color_bnw(const RGBA4F&);
        void    set_color_bne(const RGBA4F&);
        void    set_color_tsw(const RGBA4F&);
        void    set_color_tse(const RGBA4F&);
        void    set_color_tnw(const RGBA4F&);
        void    set_color_tne(const RGBA4F&);

    protected:
        
        virtual void rebuild() override;

    private:
        VB1<VertexC>    m_vbo;
    };
}

