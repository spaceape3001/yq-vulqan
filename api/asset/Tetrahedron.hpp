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
        class Tetrahedron : public Render3D {
            YQ_OBJECT_DECLARE(Tetrahedron, Render3D)
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

