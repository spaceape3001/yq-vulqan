////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/data/ColorVertexData.hpp>
#include <tachyon/aspect/AVertices3.hpp>
#include <tachyon/rendered/AbstractShape3.hpp>

#include <array>

namespace yq {
    template <typename> struct TetrahedronData;
}

namespace yq::tachyon {

    /*! \brief Tetrahedron
    
        This can render as a tetrahedron in the scene 
        with the specified color/vertex corners.
    */
    class Tetrahedron³ : public AbstractShape³, public AVertices³<4> {
        YQ_TACHYON_DECLARE(Tetrahedron³, AbstractShape³)
    public:

        using MyVertices  = AVertices³<4>;
        
        using ADrawMode::draw_mode;
        
        DrawMode            draw_mode(use_k) const override;
        
        using MyVertices::vertices;
        virtual bool        vertices(color_k) const { return true; }
        virtual bool        vertices(tex_k) const { return true; }
        

        const Vertex³&      vertex1() const { return m_vertices[0]; }
        const Vector3D&     point1() const { return vertex1().point; }
        const RGBA4F&       color1() const { return vertex1().color; }
        const UV2F&         uv1() const { return vertex1().uv; }
        
        double              x1() const { return point1().x; }
        double              y1() const { return point1().y; }
        double              z1() const { return point1().z; }

        float               red1() const { return color1().red; }
        float               green1() const { return color1().green; }
        float               blue1() const { return color1().blue; }
        float               alpha1() const { return color1().alpha; }

        float               u1() const { return uv1().u; }
        float               v1() const { return uv1().v; }

        void                set_vertex1(const Vertex³&);
        void                set_point1(const Vector3D&);
        void                set_color1(const RGBA4F&);
        void                set_uv1(const UV2F&);

        const Vertex³&      vertex2() const { return m_vertices[1]; }
        const Vector3D&     point2() const { return vertex2().point; }
        const RGBA4F&       color2() const { return vertex2().color; }
        const UV2F&         uv2() const { return vertex2().uv; }
        
        double              x2() const { return point2().x; }
        double              y2() const { return point2().y; }
        double              z2() const { return point2().z; }

        float               red2() const { return color2().red; }
        float               green2() const { return color2().green; }
        float               blue2() const { return color2().blue; }
        float               alpha2() const { return color2().alpha; }

        float               u2() const { return uv2().u; }
        float               v2() const { return uv2().v; }

        void                set_vertex2(const Vertex³&);
        void                set_point2(const Vector3D&);
        void                set_color2(const RGBA4F&);
        void                set_uv2(const UV2F&);


        const Vertex³&      vertex3() const { return m_vertices[2]; }
        const Vector3D&     point3() const { return vertex3().point; }
        const RGBA4F&       color3() const { return vertex3().color; }
        const UV2F&         uv3() const { return vertex3().uv; }
        
        double              x3() const { return point3().x; }
        double              y3() const { return point3().y; }
        double              z3() const { return point3().z; }

        float               red3() const { return color3().red; }
        float               green3() const { return color3().green; }
        float               blue3() const { return color3().blue; }
        float               alpha3() const { return color3().alpha; }

        float               u3() const { return uv3().u; }
        float               v3() const { return uv3().v; }

        void                set_vertex3(const Vertex³&);
        void                set_point3(const Vector3D&);
        void                set_color3(const RGBA4F&);
        void                set_uv3(const UV2F&);

        const Vertex³&      vertex4() const { return m_vertices[3]; }
        const Vector3D&     point4() const { return vertex4().point; }
        const RGBA4F&       color4() const { return vertex4().color; }
        const UV2F&         uv4() const { return vertex4().uv; }
        
        double              x4() const { return point4().x; }
        double              y4() const { return point4().y; }
        double              z4() const { return point4().z; }

        float               red4() const { return color4().red; }
        float               green4() const { return color4().green; }
        float               blue4() const { return color4().blue; }
        float               alpha4() const { return color4().alpha; }

        float               u4() const { return uv4().u; }
        float               v4() const { return uv4().v; }

        void                set_vertex4(const Vertex³&);
        void                set_point4(const Vector3D&);
        void                set_color4(const RGBA4F&);
        void                set_uv4(const UV2F&);


        //! Constructor taking in the data
        Tetrahedron³(const TetrahedronData<ColorVertex3D>&, const Param& p={});
        Tetrahedron³(const Vertex³&, const Vertex³&, const Vertex³&, const Vertex³&, const Param&p = {});
        Tetrahedron³(const Param&p = {});

        //! Destructor
        ~Tetrahedron³();
        
        //! Internal use, initializes the tetrahedron meta information
        static void init_info();
        
    protected:
        Vertex³&      vertex1() { return m_vertices[0]; }
        Vertex³&      vertex2() { return m_vertices[1]; }
        Vertex³&      vertex3() { return m_vertices[2]; }
        Vertex³&      vertex4() { return m_vertices[3]; }

        static const Vertex³ kDefVertex1;
        static const Vertex³ kDefVertex2;
        static const Vertex³ kDefVertex3;
        static const Vertex³ kDefVertex4;

        virtual void    rebuild() override;
        
        void        rebuild_bicolor();
        void        rebuild_color();
        void        rebuild_gradient();
        void        rebuild_textured();
    };
}
