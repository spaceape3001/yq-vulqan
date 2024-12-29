////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/ColorVertexData.hpp>
#include <yq/tachyon/api/VBO.hpp>
#include <yq/tachyon/api/Rendered³.hpp>

#include <array>

namespace yq {
    template <typename> struct TetrahedronData;
}

namespace yq::tachyon {

    /*! \brief Tetrahedron
    
        This can render as a tetrahedron in the scene 
        with the specified color/vertex corners.
    */
    class Tetrahedron³ : public Rendered³ {
        YQ_TACHYON_DECLARE(Tetrahedron³, Rendered³)
    public:

        //! Constructor taking in the data
        Tetrahedron³(const TetrahedronData<ColorVertex3D>&, const Param& p={});
        
        //! Destructor
        ~Tetrahedron³();
        
        //! Internal use, initializes the tetrahedron meta information
        static void init_info();
        
    private:
        VB1<ColorVertexData>   m_vertex;
    };
}
