////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Proxy.hpp>
#include <tachyon/interface/IVertices3.hpp>

namespace yq::tachyon {
    class PVertices³ : public Proxy, public IVertices³ {
    public:
        
        PVertices³(const IVertices³&);
        ~PVertices³();

        bool                appendable() const;
        bool                settable() const;
        bool                erasable() const;
        bool                insertable() const;

        virtual size_t      vertices(count_k) const override;
        virtual size_t      vertices(maximum_k) const override;
        virtual size_t      vertices(minimum_k) const override;
        virtual bool        vertices(appendable_k) const override;
        virtual bool        vertices(disabled_k) const override;
        virtual bool        vertices(insertable_k) const override;
        virtual bool        vertices(settable_k) const override;
        virtual bool        vertices(erasable_k) const override;
        virtual bool        vertices(color_k) const override;
        virtual bool        vertices(normal_k) const override;
        virtual bool        vertices(point_k) const override;
        virtual bool        vertices(tex_k) const override;

        virtual bool        vertices(settable_k, color_k) const override;
        virtual bool        vertices(settable_k, normal_k) const override;
        virtual bool        vertices(settable_k, point_k) const override;
        virtual bool        vertices(settable_k, tex_k) const override;

        virtual Vertex³     vertex(size_t) const override;
        virtual Vector3D    vertex(size_t, point_k) const override;
        virtual RGBA4F      vertex(size_t, color_k) const override;
        virtual UV2F        vertex(size_t, tex_k) const override;
        virtual Vector3F    vertex(size_t, normal_k) const override;

        virtual void        vertex(append_k, const Vertex³&) override;
        virtual void        vertex(size_t, set_k, const Vertex³&) override;
        virtual void        vertex(size_t, set_k, point_k, const Vector3D&) override;
        virtual void        vertex(size_t, set_k, color_k, const RGBA4F&) override;
        virtual void        vertex(size_t, set_k, tex_k, const UV2F&) override;
        virtual void        vertex(size_t, set_k, normal_k, const Vector3F&) override;
        virtual void        vertex(size_t, insert_k, const Vertex³&) override;
        virtual void        vertex(size_t, erase_k) override;

    private:
        std::vector<Vector3D>   m_vertices;
        std::vector<RGBA4F>     m_colors;
        std::vector<Vector3F>   m_normals;
        std::vector<UV2F>       m_texs;
        
        size_t  m_count     = 0;
        size_t  m_maxCount  = SIZE_MAX;
        size_t  m_minCount  = 0;
        
        enum class P {
            Appendable,
            Insertable,
            Settable,
            Erasable,
            Color,
            Tex,
            Normal,
            Point,
            SettablePoint,
            SettableColor,
            SettableTex,
            SettableNormal
        };
        
        Flags<P>    m_pflags = {};
    };
}
