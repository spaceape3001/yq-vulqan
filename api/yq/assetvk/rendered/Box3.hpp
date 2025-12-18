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
    class Box³ : public Shape³, public AVertices³<8> {
        YQ_TACHYON_DECLARE(Box³, Shape³)
    public:
    
        struct Param : public Shape³::Param {
        };

        using MyVertices  = AVertices³<8>;

        using MyVertices::vertices;
        virtual bool        vertices(settable_k) const override { return true; }
        virtual bool        vertices(color_k) const override;

        virtual bool        vertices(point_k) const override { return true; }
        virtual bool        vertices(settable_k, point_k) const override { return false; }
        //virtual bool    vertices(color_k) const override { return true; }
        
        using Shape³::draw_mode;
        virtual DrawMode    draw_mode(use_k) const override;

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

        Box³();
        Box³(const Param&);
        
        static void init_meta();


        const RGBA4F& color_bsw() const { return vertex_bsw().color; }
        const RGBA4F& color_bse() const { return vertex_bse().color; }
        const RGBA4F& color_bnw() const { return vertex_bnw().color; }
        const RGBA4F& color_bne() const { return vertex_bne().color; }
        const RGBA4F& color_tsw() const { return vertex_tsw().color; }
        const RGBA4F& color_tse() const { return vertex_tse().color; }
        const RGBA4F& color_tnw() const { return vertex_tnw().color; }
        const RGBA4F& color_tne() const { return vertex_tne().color; }

        float   red_bsw() const { return color_bsw().red; }
        float   red_bse() const { return color_bse().red; }
        float   red_bnw() const { return color_bnw().red; }
        float   red_bne() const { return color_bne().red; }
        float   red_tsw() const { return color_tsw().red; }
        float   red_tse() const { return color_tse().red; }
        float   red_tnw() const { return color_tnw().red; }
        float   red_tne() const { return color_tne().red; }
        
        float   green_bsw() const { return color_bsw().green; }
        float   green_bse() const { return color_bse().green; }
        float   green_bnw() const { return color_bnw().green; }
        float   green_bne() const { return color_bne().green; }
        float   green_tsw() const { return color_tsw().green; }
        float   green_tse() const { return color_tse().green; }
        float   green_tnw() const { return color_tnw().green; }
        float   green_tne() const { return color_tne().green; }

        float   blue_bsw() const { return color_bsw().blue; }
        float   blue_bse() const { return color_bse().blue; }
        float   blue_bnw() const { return color_bnw().blue; }
        float   blue_bne() const { return color_bne().blue; }
        float   blue_tsw() const { return color_tsw().blue; }
        float   blue_tse() const { return color_tse().blue; }
        float   blue_tnw() const { return color_tnw().blue; }
        float   blue_tne() const { return color_tne().blue; }

        float   alpha_bsw() const { return color_bsw().alpha; }
        float   alpha_bse() const { return color_bse().alpha; }
        float   alpha_bnw() const { return color_bnw().alpha; }
        float   alpha_bne() const { return color_bne().alpha; }
        float   alpha_tsw() const { return color_tsw().alpha; }
        float   alpha_tse() const { return color_tse().alpha; }
        float   alpha_tnw() const { return color_tnw().alpha; }
        float   alpha_tne() const { return color_tne().alpha; }
        
        void    set_color_bsw(const RGBA4F&);
        void    set_color_bse(const RGBA4F&);
        void    set_color_bnw(const RGBA4F&);
        void    set_color_bne(const RGBA4F&);
        void    set_color_tsw(const RGBA4F&);
        void    set_color_tse(const RGBA4F&);
        void    set_color_tnw(const RGBA4F&);
        void    set_color_tne(const RGBA4F&);

        virtual ~Box³();
        
    protected:

    
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
        void            reshape();

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
