////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Render³.hpp>
#include <yq/tachyon/api/ColorVertexData.hpp>
#include <yq/tachyon/api/VBO.hpp>

#include <array>

namespace yq {
    template <typename> struct TriangleData;
}

namespace yq::tachyon {

    /*! \brief Triangle for three dimensions
    */
    class Triangle³ : public Render³ {
        YQ_TACHYON_DECLARE(Triangle³, Render³)
    public:
    
        Triangle³(const TriangleData<ColorVertex2D>&);
        ~Triangle³();
        
        static void init_info();
        
    private:
        VB1<ColorVertexData>    m_vertex;
    };
}
