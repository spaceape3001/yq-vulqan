////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/Render3D.hpp>
#include <tachyon/VBO.hpp>
#include <array>
#include <tachyon/data/ColorVertexData.hpp>

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
        
        static void initInfo();
        
    private:
        VB1<ColorVertexData>    m_vertex;
    };
}
