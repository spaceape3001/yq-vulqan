////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Render³D.hpp>
#include <yq/tachyon/api/ColorVertexData.hpp>
#include <yq/tachyon/api/VBO.hpp>

#include <array>

namespace yq {
    template <typename> struct TriangleData;
}

namespace yq::tachyon {

    /*! \brief Triangle for three dimensions
    */
    class Triangle³ : public Render³D {
        YQ_TACHYON_DECLARE(Triangle³, Render³D)
    public:
    
        Triangle³(const TriangleData<ColorVertex2D>&);
        ~Triangle³();
        
        static void init_info();
        
    private:
        VB1<ColorVertexData>    m_vertex;
    };
}
