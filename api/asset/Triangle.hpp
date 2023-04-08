////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/scene/Render3D.hpp>
#include <array>
#include <data/ColorVertexData.hpp>

namespace yq {
    namespace tachyon {
        class Triangle : public Render3D {
            YQ_OBJECT_DECLARE(Triangle, Render3D)
        public:
        
            Triangle(const TriangleData<ColorVertex2D>&);
            ~Triangle();
            
            static void initInfo();
            
        private:
        
            std::array<ColorVertexData,3>        m_vertex;
        };
    }
}

