////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/AVertices3.hpp>
#include <yq/tachyon/aspect/ASize3.hpp>
#include <yq/tachyon/pipeline/VBO.hpp>
#include <yq/tachyon/pipeline/UBO.hpp>
#include <yq/tachyon/rendered/Shape3.hpp>

namespace yq::tachyon {
    class Diamond³ : public Shape³, public AVertices³<6> {
        YQ_TACHYON_DECLARE(Diamond³, Shape³)
    public:
    
        using Param = Shape³::Param;
    
        using MyVertices  = AVertices³<6>;

        using MyVertices::vertices;

        using AColor::color;
        virtual bool    color(settable_k) const override { return true; }

        using Shape³::draw_mode;
        virtual DrawMode    draw_mode(use_k) const override;
    
        virtual bool    vertices(point_k) const override { return true; }
        virtual bool    vertices(settable_k, point_k) const override { return false; }
        virtual bool    vertices(settable_k, color_k) const override { return true; }
        virtual bool    vertices(settable_k, tex_k) const override { return true; }
        virtual bool    vertices(settable_k, normal_k) const override { return true; }
        virtual bool    vertices(color_k) const override;

        //virtual bool    vertices(color_k) const override { return true; }
        
        static constexpr const size_t kEast     = 0;
        static constexpr const size_t kWest     = 1;
        static constexpr const size_t kNorth    = 2;
        static constexpr const size_t kSouth    = 3;
        static constexpr const size_t kTop      = 4;
        static constexpr const size_t kBottom   = 5;
    
        const Vertex³&      vertex_east() const { return m_vertices[kEast]; }
        const Vertex³&      vertex_west() const { return m_vertices[kWest]; }
        const Vertex³&      vertex_north() const { return m_vertices[kNorth]; }
        const Vertex³&      vertex_south() const { return m_vertices[kSouth]; }
        const Vertex³&      vertex_top() const { return m_vertices[kTop]; }
        const Vertex³&      vertex_bottom() const { return m_vertices[kBottom]; }

        const Vector3D&     point_east() const      { return vertex_east().point; }
        const Vector3D&     point_west() const      { return vertex_west().point; }
        const Vector3D&     point_north() const     { return vertex_north().point; }
        const Vector3D&     point_south() const     { return vertex_south().point; }
        const Vector3D&     point_top() const       { return vertex_top().point; }
        const Vector3D&     point_bottom() const    { return vertex_bottom().point; }

        double              x_east() const { return point_east().x; }
        double              x_west() const { return point_west().x; }
        double              x_south() const { return point_south().x; }
        double              x_north() const { return point_north().x; }
        double              x_top() const { return point_top().x; }
        double              x_bottom() const { return point_bottom().x; }

        double              y_east() const { return point_east().y; }
        double              y_west() const { return point_west().y; }
        double              y_south() const { return point_south().y; }
        double              y_north() const { return point_north().y; }
        double              y_top() const { return point_top().y; }
        double              y_bottom() const { return point_bottom().y; }

        double              z_east() const { return point_east().z; }
        double              z_west() const { return point_west().z; }
        double              z_south() const { return point_south().z; }
        double              z_north() const { return point_north().z; }
        double              z_top() const { return point_top().z; }
        double              z_bottom() const { return point_bottom().z; }

        const RGBA4F&       color_east() const { return vertex_east().color; }
        const RGBA4F&       color_west() const { return vertex_west().color; }
        const RGBA4F&       color_north() const { return vertex_north().color; }
        const RGBA4F&       color_south() const { return vertex_south().color; }
        const RGBA4F&       color_top() const { return vertex_top().color; }
        const RGBA4F&       color_bottom() const { return vertex_bottom().color; }

        void                set_color_east(const RGBA4F&);
        void                set_color_west(const RGBA4F&);
        void                set_color_north(const RGBA4F&);
        void                set_color_south(const RGBA4F&);
        void                set_color_top(const RGBA4F&);
        void                set_color_bottom(const RGBA4F&);

        float               red_east() const { return color_east().red; }
        float               red_west() const { return color_west().red; }
        float               red_north() const { return color_north().red; }
        float               red_south() const { return color_south().red; }
        float               red_top() const { return color_top().red; }
        float               red_bottom() const { return color_bottom().red; }

        float               green_east() const { return color_east().green; }
        float               green_west() const { return color_west().green; }
        float               green_north() const { return color_north().green; }
        float               green_south() const { return color_south().green; }
        float               green_top() const { return color_top().green; }
        float               green_bottom() const { return color_bottom().green; }

        float               blue_east() const { return color_east().blue; }
        float               blue_west() const { return color_west().blue; }
        float               blue_north() const { return color_north().blue; }
        float               blue_south() const { return color_south().blue; }
        float               blue_top() const { return color_top().blue; }
        float               blue_bottom() const { return color_bottom().blue; }

        float               alpha_east() const { return color_east().alpha; }
        float               alpha_west() const { return color_west().alpha; }
        float               alpha_north() const { return color_north().alpha; }
        float               alpha_south() const { return color_south().alpha; }
        float               alpha_top() const { return color_top().alpha; }
        float               alpha_bottom() const { return color_bottom().alpha; }

        const UV2F&         uv_east() const { return vertex_east().uv; }
        const UV2F&         uv_west() const { return vertex_west().uv; }
        const UV2F&         uv_north() const { return vertex_north().uv; }
        const UV2F&         uv_south() const { return vertex_south().uv; }
        const UV2F&         uv_top() const { return vertex_top().uv; }
        const UV2F&         uv_bottom() const { return vertex_bottom().uv; }
        
        float               u_east() const { return uv_east().u; }
        float               u_west() const { return uv_west().u; }
        float               u_north() const { return uv_north().u; }
        float               u_south() const { return uv_south().u; }
        float               u_top() const { return uv_top().u; }
        float               u_bottom() const { return uv_bottom().u; }

        float               v_east() const { return uv_east().v; }
        float               v_west() const { return uv_west().v; }
        float               v_north() const { return uv_north().v; }
        float               v_south() const { return uv_south().v; }
        float               v_top() const { return uv_top().v; }
        float               v_bottom() const { return uv_bottom().v; }

        void                set_uv_east(const UV2F&);
        void                set_uv_west(const UV2F&);
        void                set_uv_north(const UV2F&);
        void                set_uv_south(const UV2F&);
        void                set_uv_top(const UV2F&);
        void                set_uv_bottom(const UV2F&);
        
        Diamond³();
        Diamond³(const Param&);
        virtual ~Diamond³();
        
        static void init_meta();

    protected:

    
        Vertex³&            vertex_east()   { return m_vertices[kEast]; }
        Vertex³&            vertex_west()   { return m_vertices[kWest]; }
        Vertex³&            vertex_north()  { return m_vertices[kNorth]; }
        Vertex³&            vertex_south()  { return m_vertices[kSouth]; }
        Vertex³&            vertex_top()    { return m_vertices[kTop]; }
        Vertex³&            vertex_bottom() { return m_vertices[kBottom]; }

        //  This will rebuild the vertex positions....
        virtual void    rebuild() override;
        
        void                reshape();

        static const uint16_t   s_kIndices[];
        static IBO<uint16_t>    s_indices;

        VB1<VertexC>    m_vertexC;
        VB1<VertexCT>   m_vertexCT;
        VB1<VertexT>    m_vertexT;
        VB1<VertexS>    m_vertexS;

        UB1<UBS>        m_uniformS;
        //TextureCPtr     m_texture;
    };
}
