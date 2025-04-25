////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/data/ColorVertexData.hpp>
#include <tachyon/gfx/VBO.hpp>
#include <tachyon/api/Rendered3.hpp>
#include <array>

namespace yq {
    template <typename> struct QuadrilateralData;
}

namespace yq::tachyon {

    /*! \brief A quadrilateral, taking in four points */
    class Quadrilateral³ : public Rendered³ {
        YQ_TACHYON_DECLARE(Quadrilateral³, Rendered³)
    public:
    
        Quadrilateral³(const QuadrilateralData<ColorVertex2D>&, const Param& p={});
        ~Quadrilateral³();
        
        static void init_info();
        
    private:
        VB1<ColorVertexData>    m_vertex;
    };
}
