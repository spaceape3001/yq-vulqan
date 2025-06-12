////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/rendered/Triangle3.hpp>
#include <tachyon/data/ColorVertexData.hpp>
#include <tachyon/gfx/VBO.hpp>
#include <yq/typedef/vector3.hpp>

#include <array>

namespace yq {
    template <typename> struct TriangleData;
}

namespace yq::tachyon {
    struct ColorVertex2D;
    struct ColorVertex3D;

    /*! \brief Triangle for three dimensions
    */
    class ColorTriangle³ : public Triangle³ {
        YQ_TACHYON_DECLARE(ColorTriangle³, Triangle³)
    public:
    
        ColorTriangle³(const TriangleData<ColorVertex3D>&, const Param& p={});
        ColorTriangle³(const TriangleData<ColorVertex2D>&, const Param& p={});
        ColorTriangle³(const Vertex³&, const Vertex³&, const Vertex³&, const Param& p = {});
        ColorTriangle³(const Param& p={});
        ~ColorTriangle³();
        
        static void init_info();
        
    protected:
        
        virtual void    rebuild() override;
        
    private:
    
        struct Vertex {
            glm::vec3       position;
            glm::vec4       color;
        };
        
        static Vertex   vq(const Vertex³&);

        VB1<Vertex>     m_vertex;
    };
}
