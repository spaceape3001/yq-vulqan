////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/rendered/Tetrahedron3.hpp>

#include <array>

namespace yq {
    template <typename> struct TetrahedronData;
}

namespace yq::tachyon {

    /*! \brief Gradient Tetrahedron
    
        This can render as a tetrahedron in the scene 
        with the specified color/vertex corners.
    */
    class GradTetrahedron³ : public Tetrahedron³ {
        YQ_TACHYON_DECLARE(GradTetrahedron³, Tetrahedron³)
    public:

        using MyVertices::vertices;
        virtual bool        vertices(color_k) const { return true; }
        
        //! Constructor taking in the data
        GradTetrahedron³(const TetrahedronData<ColorVertex3D>&, const Param& p={});
        GradTetrahedron³(const Vertex³&, const Vertex³&, const Vertex³&, const Vertex³&, const Param&p = {});
        GradTetrahedron³(const Param&p = {});

        //! Destructor
        ~GradTetrahedron³();
        
        //! Internal use, initializes the tetrahedron meta information
        static void init_meta();

        const RGBA4F&       color1() const { return vertex1().color; }
        const RGBA4F&       color2() const { return vertex2().color; }
        const RGBA4F&       color3() const { return vertex3().color; }
        const RGBA4F&       color4() const { return vertex4().color; }

        void                set_color1(const RGBA4F&);
        void                set_color2(const RGBA4F&);
        void                set_color3(const RGBA4F&);
        void                set_color4(const RGBA4F&);

        float               red1() const { return color1().red; }
        float               red2() const { return color2().red; }
        float               red3() const { return color3().red; }
        float               red4() const { return color4().red; }

        float               green1() const { return color1().green; }
        float               green2() const { return color2().green; }
        float               green3() const { return color3().green; }
        float               green4() const { return color4().green; }

        float               blue1() const { return color1().blue; }
        float               blue2() const { return color2().blue; }
        float               blue3() const { return color3().blue; }
        float               blue4() const { return color4().blue; }

        float               alpha1() const { return color1().alpha; }
        float               alpha2() const { return color2().alpha; }
        float               alpha3() const { return color3().alpha; }
        float               alpha4() const { return color4().alpha; }

        
    protected:

        virtual void    rebuild() override;

    private:
        VB1<VertexC>    m_vbo;
    };
}

YQ_TACHYON_FORCE(yq::tachyon::GradTetrahedron³)

