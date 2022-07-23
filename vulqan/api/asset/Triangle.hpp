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
        class Triangle : public engine::Render3D {
            YQ_OBJECT_DECLARE(Triangle, engine::Render3D)
        public:
        
            Triangle(const TriangleData<ColorVertex2D>&);
            ~Triangle();
            
            static void initInfo();
            
        private:
        
            std::array<ColorVertexData,3>        m_vertex;
        };
    }
}

