////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/render/Render3D.hpp>
#include <tachyon/data/ColorVertexData.hpp>
#include <tachyon/pipeline/VBO.hpp>

#include <array>

namespace yq {
    template <typename> struct TriangleData;
}

namespace yq::tachyon {

    /*! \brief Triangle
    
        This is a 2D triangle -- should be on a 2D render, but it's 3D.
    */
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
