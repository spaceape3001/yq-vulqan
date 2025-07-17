////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/aspect/AVertices3.hpp>
#include <tachyon/aspect/ASize3.hpp>
#include <tachyon/rendered/AbstractShape3.hpp>
#include <tachyon/pipeline/VBO.hpp>
#include <tachyon/pipeline/UBO.hpp>

namespace yq::tachyon {
    class Box³ : public AbstractShape³, public AVertices³<8>, public ASize³ {
        YQ_TACHYON_DECLARE(Box³, AbstractShape³)
    public:
    
        using MyVertices  = AVertices³<8>;

        using MyVertices::vertices;
    
        virtual bool    vertices(point_k) const override { return true; }
        virtual bool    vertices(settable_k, point_k) const override { return false; }
        //virtual bool    vertices(color_k) const override { return true; }
        
        using ASize³::size;
        virtual bool    size(settable_k) const override { return true; }
    
        const Vertex³&      vertex_bsw() const { return m_vertices[0]; }
        const Vertex³&      vertex_bse() const { return m_vertices[1]; }
        const Vertex³&      vertex_bne() const { return m_vertices[2]; }
        const Vertex³&      vertex_bnw() const { return m_vertices[3]; }
        const Vertex³&      vertex_tsw() const { return m_vertices[4]; }
        const Vertex³&      vertex_tse() const { return m_vertices[5]; }
        const Vertex³&      vertex_tne() const { return m_vertices[6]; }
        const Vertex³&      vertex_tnw() const { return m_vertices[7]; }

        const Vector3D&     point_bsw() const { return vertex_bsw().point; }
        const Vector3D&     point_bse() const { return vertex_bse().point; }
        const Vector3D&     point_bnw() const { return vertex_bnw().point; }
        const Vector3D&     point_bne() const { return vertex_bne().point; }
        const Vector3D&     point_tsw() const { return vertex_tsw().point; }
        const Vector3D&     point_tse() const { return vertex_tse().point; }
        const Vector3D&     point_tnw() const { return vertex_tnw().point; }
        const Vector3D&     point_tne() const { return vertex_tne().point; }

        double              x_bsw() const { return point_bsw().x; }
        double              x_bse() const { return point_bse().x; }
        double              x_bnw() const { return point_bnw().x; }
        double              x_bne() const { return point_bne().x; }
        double              x_tsw() const { return point_tsw().x; }
        double              x_tse() const { return point_tse().x; }
        double              x_tnw() const { return point_tnw().x; }
        double              x_tne() const { return point_tne().x; }

        double              y_bsw() const { return point_bsw().y; }
        double              y_bse() const { return point_bse().y; }
        double              y_bnw() const { return point_bnw().y; }
        double              y_bne() const { return point_bne().y; }
        double              y_tsw() const { return point_tsw().y; }
        double              y_tse() const { return point_tse().y; }
        double              y_tnw() const { return point_tnw().y; }
        double              y_tne() const { return point_tne().y; }

        double              z_bsw() const { return point_bsw().z; }
        double              z_bse() const { return point_bse().z; }
        double              z_bnw() const { return point_bnw().z; }
        double              z_bne() const { return point_bne().z; }
        double              z_tsw() const { return point_tsw().z; }
        double              z_tse() const { return point_tse().z; }
        double              z_tnw() const { return point_tnw().z; }
        double              z_tne() const { return point_tne().z; }

        Box³(const Size3D& sz=kDefSize, const Param& p = Param());
        Box³(const AxBox3D& bx, const Param& p = Param());
        
        static void init_meta();

    protected:

        virtual ~Box³();
    
        static Param    set_position(const AxBox3D& sz, const Param&);
    
        Vertex³&            vertex_bsw()  { return m_vertices[0]; }
        Vertex³&            vertex_bse()  { return m_vertices[1]; }
        Vertex³&            vertex_bne()  { return m_vertices[2]; }
        Vertex³&            vertex_bnw()  { return m_vertices[3]; }
        Vertex³&            vertex_tsw()  { return m_vertices[4]; }
        Vertex³&            vertex_tse()  { return m_vertices[5]; }
        Vertex³&            vertex_tne()  { return m_vertices[6]; }
        Vertex³&            vertex_tnw()  { return m_vertices[7]; }

        //  This will rebuild the vertex positions....
        virtual void    rebuild() override;

        static const uint16_t   s_kIndices[];
        static IBO<uint16_t>    s_indices;
    };
}
