////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/data/ColorVertexData.hpp>
#include <tachyon/aspect/AColor.hpp>
#include <tachyon/rendered/Tetrahedron3.hpp>
#include <tachyon/pipeline/UBO.hpp>

#include <array>

namespace yq {
    template <typename> struct TetrahedronData;
}

namespace yq::tachyon {

    /*! \brief Tetrahedron
    
        This can render as a tetrahedron in the scene 
        with the specified color/vertex corners.
    */
    class ColorTetrahedron³ : public Tetrahedron³, public AColor {
        YQ_TACHYON_DECLARE(ColorTetrahedron³, Tetrahedron³)
    public:
    
        struct Param : public Tetrahedron³::Param {
            RGBA4F  color   = kDefColor;
            
            Param(){}
        };

        using AColor::color;
        virtual bool    color(settable_k) const override { return true; }

        //! Constructor taking in the data
        ColorTetrahedron³(const TetrahedronData<ColorVertex3D>&, const Param& p={});
        ColorTetrahedron³(const Vertex³&, const Vertex³&, const Vertex³&, const Vertex³&, const Param&p = {});
        ColorTetrahedron³(const Param&p = {});

        //! Destructor
        ~ColorTetrahedron³();
        
        //! Internal use, initializes the tetrahedron meta information
        static void init_meta();
        
    protected:
        virtual void    rebuild() override;

        VB1<VertexS>    m_vbo;
        UB1<UBS>        m_ubo;
    };
}

YQ_TACHYON_FORCE(yq::tachyon::ColorTetrahedron³)
