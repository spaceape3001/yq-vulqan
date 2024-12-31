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
    template <typename> struct QuadrilateralData;
}

namespace yq::tachyon {

    /*! \brief A quadrilateral, taking in four points */
    class Quadrilateral3 : public Rendered3 {
        YQ_TACHYON_DECLARE(Quadrilateral3, Rendered3)
    public:
    
        Quadrilateral3(const QuadrilateralData<ColorVertex2D>&, const Param& p={});
        ~Quadrilateral3();
        
        static void init_info();
        
    private:
        VB1<ColorVertexData>    m_vertex;
    };
}
