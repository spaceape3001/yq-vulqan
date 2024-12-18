////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/data/ColorVertexData.hpp>
#include <yq/tachyon/buffer/VBO.hpp>
#include <yq/tachyon/render/Render3D.hpp>

#include <array>

namespace yq {
    template <typename> struct TetrahedronData;
}

namespace yq::tachyon {

    /*! \brief Tetrahedron
    
        This can render as a tetrahedron in the scene 
        with the specified color/vertex corners.
    */
    class Tetrahedron : public Render3D {
        YQ_OBJECT_DECLARE(Tetrahedron, Render3D)
    public:

        //! Constructor taking in the data
        Tetrahedron(const TetrahedronData<ColorVertex3D>&);
        
        //! Destructor
        ~Tetrahedron();
        
        //! Internal use, initializes the tetrahedron meta information
        static void init_info();
        
    private:
        VB1<ColorVertexData>   m_vertex;
    };
}
