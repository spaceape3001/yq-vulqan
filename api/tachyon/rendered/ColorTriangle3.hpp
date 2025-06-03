////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Rendered3.hpp>
#include <tachyon/data/ColorVertexData.hpp>
#include <tachyon/gfx/VBO.hpp>
#include <yq/typedef/vector3.hpp>

#include <array>

namespace yq {
    template <typename> struct TriangleData;
}

namespace yq::tachyon {

    /*! \brief Triangle for three dimensions
    */
    class ColorTriangle³ : public Rendered³ {
        YQ_TACHYON_DECLARE(ColorTriangle³, Rendered³)
    public:
    
        ColorTriangle³();
        ~ColorTriangle³();
        
        static void init_info();
        
        RGBA4F      color1() const;
        RGBA4F      color2() const;
        RGBA4F      color3() const;
        
        Vector3F    vertex1() const;
        Vector3F    vertex2() const;
        Vector3F    vertex3() const;
        
        void        set_color1(RGBA4F);
        void        set_color2(RGBA4F);
        void        set_color3(RGBA4F);
        
        void        set_vertex1(Vector3F);
        void        set_vertex2(Vector3F);
        void        set_vertex3(Vector3F);
        
    protected:
        Execution   tick(const Context&);
        
    private:
        VB1<ColorVertexData>    m_vertex;
    };
}
