////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/rendered/Triangle3.hpp>
#include <yq/tachyon/pipeline/VBO.hpp>

namespace yq::tachyon {
    /*! \brief Triangle for three dimensions
    */
    class GradTriangle³ : public Triangle³ {
        YQ_TACHYON_DECLARE(GradTriangle³, Triangle³)
    public:

        static void         init_meta();
        
        GradTriangle³(const TriangleData<ColorVertex3D>&, const Param& p={});
        GradTriangle³(const TriangleData<ColorVertex2D>&, const Param& p={});
        GradTriangle³(const Vertex³&, const Vertex³&, const Vertex³&, const Param&p = {});
        GradTriangle³(const Param&p = {});
        ~GradTriangle³();

        const RGBA4F&       color1() const { return vertex1().color; }
        const RGBA4F&       color2() const { return vertex2().color; }
        const RGBA4F&       color3() const { return vertex3().color; }

        void                set_color1(const RGBA4F&);
        void                set_color2(const RGBA4F&);
        void                set_color3(const RGBA4F&);

        float               red1() const { return color1().red; }
        float               red2() const { return color2().red; }
        float               red3() const { return color3().red; }

        float               green1() const { return color1().green; }
        float               green2() const { return color2().green; }
        float               green3() const { return color3().green; }

        float               blue1() const { return color1().blue; }
        float               blue2() const { return color2().blue; }
        float               blue3() const { return color3().blue; }

        float               alpha1() const { return color1().alpha; }
        float               alpha2() const { return color2().alpha; }
        float               alpha3() const { return color3().alpha; }

    protected:
        virtual void    rebuild() override;

        VB1<VertexC>    m_vbo;
    };
}

YQ_TACHYON_FORCE(yq::tachyon::GradTriangle³)
