////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/ColorVertexData.hpp>
#include <yq/tachyon/api/VBO.hpp>
#include <yq/tachyon/api/Render³D.hpp>

#include <array>

namespace yq {
    template <typename> struct TetrahedronData;
}

namespace yq::tachyon {

    /*! \brief Tetrahedron
    
        This can render as a tetrahedron in the scene 
        with the specified color/vertex corners.
    */
    class Tetrahedron³ : public Render³D {
        YQ_TACHYON_DECLARE(Tetrahedron³, Render³D)
    public:

        //! Constructor taking in the data
        Tetrahedron³(const TetrahedronData<ColorVertex3D>&);
        
        //! Destructor
        ~Tetrahedron³();
        
        //! Internal use, initializes the tetrahedron meta information
        static void init_info();
        
    private:
        VB1<ColorVertexData>   m_vertex;
    };
}
