////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/assetvk/rendered/Tetrahedron3.hpp>

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


        virtual void    rebuild() override;

    private:
        VB1<VertexC>    m_vbo;
    };
}

YQ_TACHYON_FORCE(yq::tachyon::GradTetrahedron³)

