////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <engine/render/Render3D.hpp>
#include <array>
#include <math/ColorVertexData.hpp>

namespace yq {
    namespace asset {
    
        /*! \brief A quadrilateral, taking in four points */
        class Quadrilateral : public engine::Render3D {
            YQ_OBJECT_DECLARE(Quadrilateral, engine::Render3D)
        public:
        
            Quadrilateral(const QuadrilateralData<ColorVertex2D>&);
            ~Quadrilateral();
            
            static void initInfo();
            
        private:
            std::array<ColorVertexData,4>   m_vertex;
//            std::array<uint16_t,6>          m_index;
        };
    }
}

