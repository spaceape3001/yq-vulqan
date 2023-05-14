////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/scene/Render3D.hpp>
#include <array>
#include <tachyon/data/ColorVertexData.hpp>
#include <tachyon/viz/VBO.hpp>

namespace yq::tachyon {
    class Tetrahedron : public Render3D {
        YQ_OBJECT_DECLARE(Tetrahedron, Render3D)
    public:
    
        Tetrahedron(const TetrahedronData<ColorVertex3D>&);
        ~Tetrahedron();
        
        static void initInfo();
        
    private:
        VB1<ColorVertexData>   m_vertex;
    };
}
