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
    template <typename> struct QuadrilateralData;
}

namespace yq::tachyon {

    /*! \brief A quadrilateral, taking in four points */
    class Quadrilateral : public Render3D {
        YQ_OBJECT_DECLARE(Quadrilateral, Render3D)
    public:
    
        Quadrilateral(const QuadrilateralData<ColorVertex2D>&);
        ~Quadrilateral();
        
        static void init_info();
        
    private:
        VB1<ColorVertexData>    m_vertex;
    };
}
