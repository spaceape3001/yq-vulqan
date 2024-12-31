////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Rendered3.hpp>
#include <yq/tachyon/api/ColorVertexData.hpp>
#include <yq/tachyon/api/VBO.hpp>

#include <array>

namespace yq {
    template <typename> struct TriangleData;
}

namespace yq::tachyon {

    /*! \brief Triangle for three dimensions
    */
    class Triangle3 : public Rendered3 {
        YQ_TACHYON_DECLARE(Triangle3, Rendered3)
    public:
    
        Triangle3(const TriangleData<ColorVertex2D>&, const Param& p={});
        ~Triangle3();
        
        static void init_info();
        
    private:
        VB1<ColorVertexData>    m_vertex;
    };
}
