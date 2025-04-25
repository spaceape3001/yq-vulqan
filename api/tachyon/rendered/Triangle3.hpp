////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/3D/Rendered3.hpp>
#include <tachyon/data/ColorVertexData.hpp>
#include <tachyon/gfx/VBO.hpp>

#include <array>

namespace yq {
    template <typename> struct TriangleData;
}

namespace yq::tachyon {

    /*! \brief Triangle for three dimensions
    */
    class Triangle³ : public Rendered³ {
        YQ_TACHYON_DECLARE(Triangle³, Rendered³)
    public:
    
        Triangle³(const TriangleData<ColorVertex2D>&, const Param& p={});
        ~Triangle³();
        
        static void init_info();
        
    private:
        VB1<ColorVertexData>    m_vertex;
    };
}
