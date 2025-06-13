////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Rendered3.hpp>
#include <tachyon/data/ColorVertexData.hpp>
#include <tachyon/data/Vertex3.hpp>
#include <tachyon/gfx/VBO.hpp>
#include <tachyon/interface/IVertices3.hpp>
#include <tachyon/aspect/AColor.hpp>
#include <tachyon/aspect/AVertices3.hpp>
#include <tachyon/rendered/AbstractShape3.hpp>

#include <array>

namespace yq {
    template <typename> struct TriangleData;
}

namespace yq::tachyon {

    class SetVertex³Command;
    class SetVertexColorCommand;
    class SetVertexPoint³Command;
    class SetVertexUVCommand;


    /*! \brief Triangle for three dimensions
    */
    class Triangle³ : public AbstractShape³, public AVertices³<3> {
        YQ_TACHYON_DECLARE(Triangle³, AbstractShape³)
    public:
    
        using MyVertices  = AVertices³<3>;
        
        using ADrawMode::draw_mode;
        
        DrawMode            draw_mode(use_k) const override;

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

        static void         init_info();
        

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

        //PostAdvice     advise(const Post&p) const
        //{
            //info_log_post(p);
            //return AbstractShape³::advise(p);
        //}

        virtual void    rebuild() override;
        
        void        rebuild_solid();
        void        rebuild_gradient();
        void        rebuild_textured();
    };
}
