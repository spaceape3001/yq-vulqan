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
    class Triangle³ : public Rendered³, protected IVertices³  {
        YQ_TACHYON_DECLARE(Triangle³, Rendered³)
    public:
    
        size_t              vertices(count_k) const final { return 3; }
        size_t              vertices(maximum_k) const final { return 3; }
        size_t              vertices(minimum_k) const final { return 3; }
        bool                vertices(appendable_k) const override final { return false; }
        bool                vertices(insertable_k) const override final { return false; }
        bool                vertices(erasable_k) const override final { return false; }
        bool                vertices(normal_k) const override final { return false; }
        
        virtual bool        vertices(disabled_k) const override { return false; }
        virtual bool        vertices(settable_k) const override { return false; }
        virtual bool        vertices(color_k) const override { return false; }
        virtual bool        vertices(tex_k) const override { return false; }
        
        const Vector3D&     point1() const { return m_vertex1.point; }
        const Vector3D&     point2() const { return m_vertex2.point; }
        const Vector3D&     point3() const { return m_vertex3.point; }
        
        void                set_point1(const Vector3D&);
        void                set_point2(const Vector3D&);
        void                set_point3(const Vector3D&);
        
        double              x1() const { return m_vertex1.point.x; }
        double              x2() const { return m_vertex2.point.x; }
        double              x3() const { return m_vertex3.point.x; }
        double              y1() const { return m_vertex1.point.y; }
        double              y2() const { return m_vertex2.point.y; }
        double              y3() const { return m_vertex3.point.y; }
        double              z1() const { return m_vertex1.point.z; }
        double              z2() const { return m_vertex2.point.z; }
        double              z3() const { return m_vertex3.point.z; }
        
        const RGBA4F&       color1() const { return m_vertex1.color; }
        const RGBA4F&       color2() const { return m_vertex2.color; }
        const RGBA4F&       color3() const { return m_vertex3.color; }
        
        void                set_color1(const RGBA4F&);
        void                set_color2(const RGBA4F&);
        void                set_color3(const RGBA4F&);

        float               red1() const { return m_vertex1.color.red; }
        float               red2() const { return m_vertex2.color.red; }
        float               red3() const { return m_vertex3.color.red; }
        
        float               green1() const { return m_vertex1.color.green; }
        float               green2() const { return m_vertex2.color.green; }
        float               green3() const { return m_vertex3.color.green; }

        float               blue1() const { return m_vertex1.color.blue; }
        float               blue2() const { return m_vertex2.color.blue; }
        float               blue3() const { return m_vertex3.color.blue; }
        

        const UV2F&         uv1() const { return m_vertex1.uv; }
        const UV2F&         uv2() const { return m_vertex2.uv; }
        const UV2F&         uv3() const { return m_vertex3.uv; }
        
        void                set_uv1(const UV2F&);
        void                set_uv2(const UV2F&);
        void                set_uv3(const UV2F&);
        
        float               u1() const { return m_vertex1.uv.u; }
        float               u2() const { return m_vertex2.uv.u; }
        float               u3() const { return m_vertex3.uv.u; }

        float               v1() const { return m_vertex1.uv.v; }
        float               v2() const { return m_vertex2.uv.v; }
        float               v3() const { return m_vertex3.uv.v; }

        static void         init_info();
        
        //  Might consider references (later) ?
        
        virtual Vertex³     vertex(size_t) const override;
        virtual Vector3D    vertex(size_t, point_k) const override;
        virtual RGBA4F      vertex(size_t, color_k) const override;
        virtual UV2F        vertex(size_t, tex_k) const override;
        virtual void        vertex(size_t, set_k, const Vertex³&) override;
        virtual void        vertex(size_t, set_k, const Vector3D&) override;
        virtual void        vertex(size_t, set_k, color_k, const RGBA4F&) override;
        virtual void        vertex(size_t, set_k, tex_k, const UV2F&) override;

        const Vertex³&      vertex1() const { return m_vertex1; }
        const Vertex³&      vertex2() const { return m_vertex2; }
        const Vertex³&      vertex3() const { return m_vertex3; }

        void                set_vertex1(const Vertex³&);
        void                set_vertex2(const Vertex³&);
        void                set_vertex3(const Vertex³&);
        
        Execution           setup(const Context&) override;
        Execution           tick(const Context&) override;

    protected:
        Vertex³             m_vertex1{};
        Vertex³             m_vertex2{};
        Vertex³             m_vertex3{};

        Triangle³(const Vertex³&, const Vertex³&, const Vertex³&, const Param&p = {});
        Triangle³(const Param&p = {});
        ~Triangle³();

        
        //enum class V {
            //Point,
            //Color,
            //UV
        //};
        
        //using VFlags    = Flags<V,uint8_t>;

        virtual void    rebuild(){}

        void on_set_vertex_point(const SetVertexPoint³Command&);
        void on_set_vertex_color(const SetVertexColorCommand&);
        void on_set_vertex_uv(const SetVertexUVCommand&);
        void on_set_vertex_data(const SetVertex³Command&);
        
        static void create_properties(color_k, Rendered³Info::Writer<Triangle³>&);
        static void create_properties(tex_k, Rendered³Info::Writer<Triangle³>&);

    private:

        bool            m_dirty = false;

        void    _check();

        VB1<ColorVertexData>    m_vertex;
    };
}
