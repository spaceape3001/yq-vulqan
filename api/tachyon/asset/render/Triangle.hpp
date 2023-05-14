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
    class Triangle : public Render3D {
        YQ_OBJECT_DECLARE(Triangle, Render3D)
    public:
    
        Triangle(const TriangleData<ColorVertex2D>&);
        ~Triangle();
        
        static void initInfo();
        
    private:
        VB1<ColorVertexData>    m_vertex;
    };
}
