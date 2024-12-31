////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/ColorVertexData.hpp>
#include <yq/tachyon/api/VBO.hpp>
#include <yq/tachyon/api/Rendered3.hpp>

#include <array>

namespace yq {
    template <typename> struct TetrahedronData;
}

namespace yq::tachyon {

    /*! \brief Tetrahedron
    
        This can render as a tetrahedron in the scene 
        with the specified color/vertex corners.
    */
    class Tetrahedron3 : public Rendered3 {
        YQ_TACHYON_DECLARE(Tetrahedron3, Rendered3)
    public:

        //! Constructor taking in the data
        Tetrahedron3(const TetrahedronData<ColorVertex3D>&, const Param& p={});
        
        //! Destructor
        ~Tetrahedron3();
        
        //! Internal use, initializes the tetrahedron meta information
        static void init_info();
        
    private:
        VB1<ColorVertexData>   m_vertex;
    };
}
