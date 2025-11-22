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
#include <yq/tachyon/rendered/AbstractShape3.hpp>

namespace yq::tachyon {
    class Diamond³ : public AbstractShape³, public AVertices³<6>, public ASize³ {
        YQ_TACHYON_DECLARE(Diamond³, AbstractShape³)
    public:
    
        using MyVertices  = AVertices³<6>;

        using MyVertices::vertices;
    
        virtual bool    vertices(point_k) const override { return true; }
        virtual bool    vertices(settable_k, point_k) const override { return false; }
        //virtual bool    vertices(color_k) const override { return true; }
        
        using ASize³::size;
        virtual bool    size(settable_k) const override { return true; }
    
        const Vertex³&      vertex_east() const { return m_vertices[0]; }
        const Vertex³&      vertex_west() const { return m_vertices[1]; }
        const Vertex³&      vertex_north() const { return m_vertices[2]; }
        const Vertex³&      vertex_south() const { return m_vertices[3]; }
        const Vertex³&      vertex_top() const { return m_vertices[4]; }
        const Vertex³&      vertex_bottom() const { return m_vertices[5]; }

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

        Diamond³(const Size3D& sz=kDefSize, const Param& p = Param());
        Diamond³(const AxBox3D& bx, const Param& p = Param());
        
        static void init_meta();

    protected:

        virtual ~Diamond³();
    
        static Param    set_position(const AxBox3D& sz, const Param&);
    
        Vertex³&            vertex_east()   { return m_vertices[0]; }
        Vertex³&            vertex_west()   { return m_vertices[1]; }
        Vertex³&            vertex_north()  { return m_vertices[2]; }
        Vertex³&            vertex_south()  { return m_vertices[3]; }
        Vertex³&            vertex_top()    { return m_vertices[4]; }
        Vertex³&            vertex_bottom() { return m_vertices[5]; }

        //  This will rebuild the vertex positions....
        virtual void    rebuild() override;

        static const uint16_t   s_kIndices[];
        static IBO<uint16_t>    s_indices;
    };
}
