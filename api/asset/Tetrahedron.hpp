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
        class Tetrahedron : public engine::Render3D {
            YQ_OBJECT_DECLARE(Tetrahedron, engine::Render3D)
        public:
        
            Tetrahedron(const TetrahedronData<ColorVertex3D>&);
            ~Tetrahedron();
            
            static void initInfo();
            
        private:
            std::array<ColorVertexData,4>   m_vertex;
//            std::array<uint16_t,6>          m_index;
        };
    }
}

