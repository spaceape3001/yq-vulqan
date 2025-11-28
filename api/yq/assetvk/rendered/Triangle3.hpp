////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/data/ColorVertexData.hpp>
#include <yq/tachyon/data/Vertex3.hpp>
#include <yq/tachyon/aspect/AVertices3.hpp>
#include <yq/tachyon/rendered/Shape3.hpp>
#include <yq/tachyon/pipeline/VBO.hpp>
#include <yq/tachyon/pipeline/UBO.hpp>

namespace yq {
    template <typename> struct TriangleData;
}

namespace yq::tachyon {

    /*! \brief Triangle for three dimensions
    */
    class Triangle³ : public Shape³, public AVertices³<3> {
        YQ_TACHYON_DECLARE(Triangle³, Shape³)
    public:
    
        using MyVertices  = AVertices³<3>;

        using MyVertices::vertices;

        const Vertex³&      vertex1() const { return m_vertices[0]; }
        const Vertex³&      vertex2() const { return m_vertices[1]; }
        const Vertex³&      vertex3() const { return m_vertices[2]; }

        void                set_vertex1(const Vertex³&);
        void                set_vertex2(const Vertex³&);
        void                set_vertex3(const Vertex³&);

        const Vector3D&     point1() const { return vertex1().point; }
        const Vector3D&     point2() const { return vertex2().point; }
        const Vector3D&     point3() const { return vertex3().point; }

        void                set_point1(const Vector3D&);
        void                set_point2(const Vector3D&);
        void                set_point3(const Vector3D&);

        double              x1() const { return point1().x; }
        double              x2() const { return point2().x; }
        double              x3() const { return point3().x; }

        double              y1() const { return point1().y; }
        double              y2() const { return point2().y; }
        double              y3() const { return point3().y; }

        double              z1() const { return point1().z; }
        double              z2() const { return point2().z; }
        double              z3() const { return point3().z; }

#if 0
        const RGBA4F&       color1() const { return vertex1().color; }
        const RGBA4F&       color2() const { return vertex2().color; }
        const RGBA4F&       color3() const { return vertex3().color; }

        void                set_color1(const RGBA4F&);
        void                set_color2(const RGBA4F&);
        void                set_color3(const RGBA4F&);

        float               red1() const { return color1().red; }
        float               red2() const { return color2().red; }
        float               red3() const { return color3().red; }

        float               green1() const { return color1().green; }
        float               green2() const { return color2().green; }
        float               green3() const { return color3().green; }

        float               blue1() const { return color1().blue; }
        float               blue2() const { return color2().blue; }
        float               blue3() const { return color3().blue; }

        float               alpha1() const { return color1().alpha; }
        float               alpha2() const { return color2().alpha; }
        float               alpha3() const { return color3().alpha; }


        const UV2F&         uv1() const { return vertex1().uv; }
        const UV2F&         uv2() const { return vertex2().uv; }
        const UV2F&         uv3() const { return vertex3().uv; }
        
        
        float               u1() const { return uv1().u; }
        float               u2() const { return uv2().u; }
        float               u3() const { return uv3().u; }

        float               v1() const { return uv1().v; }
        float               v2() const { return uv2().v; }
        float               v3() const { return uv3().v; }

        void                set_uv1(const UV2F&);
        void                set_uv2(const UV2F&);
        void                set_uv3(const UV2F&);
#endif

        static void         init_meta();
        

        Triangle³(const TriangleData<ColorVertex3D>&, const Param& p={});
        Triangle³(const TriangleData<ColorVertex2D>&, const Param& p={});
        Triangle³(const Vertex³&, const Vertex³&, const Vertex³&, const Param&p = {});
        Triangle³(const Param&p = {});
        ~Triangle³();

    protected:
        Vertex³&      vertex1() { return m_vertices[0]; }
        Vertex³&      vertex2() { return m_vertices[1]; }
        Vertex³&      vertex3() { return m_vertices[2]; }

        static const Vertex³ kDefVertex1;
        static const Vertex³ kDefVertex2;
        static const Vertex³ kDefVertex3;

#if 0
        virtual void    rebuild();

        void    rebuild_color();
        void    rebuild_gradient();
        void    rebuild_textured();

        VB1<VertexC>    m_vertexC;
        VB1<VertexCT>   m_vertexCT;
        VB1<VertexT>    m_vertexT;
        VB1<VertexS>    m_vertexS;

        UB1<UBS>        m_uniformS;
        TextureCPtr     m_texture;
#endif
    };
}

YQ_TACHYON_FORCE(yq::tachyon::Triangle³)
