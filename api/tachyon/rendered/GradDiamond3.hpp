////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/rendered/Diamond3.hpp>
#include <tachyon/gfx/VBO.hpp>

namespace yq::tachyon {
    class GradDiamond³ : public Diamond³ {
        YQ_TACHYON_DECLARE(GradDiamond³, Diamond³)
    public:
    
        static void init_meta();
        
        GradDiamond³(const Param& p={});
        GradDiamond³(const Size3D&sz, const Param& p={});
        GradDiamond³(const AxBox3D&, const Param& p={});
        ~GradDiamond³();

        using MyVertices::vertices;
        virtual bool        vertices(color_k) const { return true; }

        const RGBA4F& color_east() const { return vertex_east().color; }
        const RGBA4F& color_west() const { return vertex_west().color; }
        const RGBA4F& color_north() const { return vertex_north().color; }
        const RGBA4F& color_south() const { return vertex_south().color; }
        const RGBA4F& color_top() const { return vertex_top().color; }
        const RGBA4F& color_bottom() const { return vertex_bottom().color; }

        float   red_east() const { return color_east().red; }
        float   red_west() const { return color_west().red; }
        float   red_north() const { return color_north().red; }
        float   red_south() const { return color_south().red; }
        float   red_top() const { return color_top().red; }
        float   red_bottom() const { return color_bottom().red; }
        
        float   green_east() const { return color_east().green; }
        float   green_west() const { return color_west().green; }
        float   green_north() const { return color_north().green; }
        float   green_south() const { return color_south().green; }
        float   green_top() const { return color_top().green; }
        float   green_bottom() const { return color_bottom().green; }

        float   blue_east() const { return color_east().blue; }
        float   blue_west() const { return color_west().blue; }
        float   blue_north() const { return color_north().blue; }
        float   blue_south() const { return color_south().blue; }
        float   blue_top() const { return color_top().blue; }
        float   blue_bottom() const { return color_bottom().blue; }

        float   alpha_east() const { return color_east().alpha; }
        float   alpha_west() const { return color_west().alpha; }
        float   alpha_north() const { return color_north().alpha; }
        float   alpha_south() const { return color_south().alpha; }
        float   alpha_top() const { return color_top().alpha; }
        float   alpha_bottom() const { return color_bottom().alpha; }
        
        void    set_color_east(const RGBA4F&);
        void    set_color_west(const RGBA4F&);
        void    set_color_north(const RGBA4F&);
        void    set_color_south(const RGBA4F&);
        void    set_color_top(const RGBA4F&);
        void    set_color_bottom(const RGBA4F&);

    protected:
        
        virtual void rebuild() override;

    private:
        VB1<VertexC>    m_vbo;
    };
}

