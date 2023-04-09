////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/scene/Render3D.hpp>
#include <array>
#include <tachyon/data/ColorVertexData.hpp>

namespace yq {
    namespace tachyon {
    
        /*! \brief A quadrilateral, taking in four points */
        class Quadrilateral : public Render3D {
            YQ_OBJECT_DECLARE(Quadrilateral, Render3D)
        public:
        
            Quadrilateral(const QuadrilateralData<ColorVertex2D>&);
            ~Quadrilateral();
            
            static void initInfo();
            
        private:
            std::array<ColorVertexData,4>        m_vertex;
        };
    }
}

