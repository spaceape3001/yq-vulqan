////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/VertexCommand.hpp>
#include <tachyon/data/Vertex3.hpp>

namespace yq::tachyon {
    class SetVertex³Command : public VertexCommand {
        YQ_OBJECT_DECLARE(SetVertex³Command, VertexCommand)
    public:
        SetVertex³Command(const Header&, size_t, const Vertex³&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        const Vertex³&  data() const { return m_data; }
        void            set_data(const Vertex³&);
        
        const Vector3D& point() const { return m_data.point; }
        void            set_point(const Vector3D&);
        
        double          x() const { return m_data.point.x; }
        double          y() const { return m_data.point.y; }
        double          z() const { return m_data.point.z; }

        const Vector3F& normal() const { return m_data.normal; }
        void            set_normal(const Vector3F&);
        
        float           nx() const { return m_data.normal.x; }
        float           ny() const { return m_data.normal.y; }
        float           nz() const { return m_data.normal.z; }
        
        const RGBA4F&   color() const { return m_data.color; }
        void            set_color(const RGBA4F&);
        
        float           red() const { return m_data.color.red; }
        float           green() const { return m_data.color.green; }
        float           blue() const { return m_data.color.blue; }
        float           alpha() const { return m_data.color.alpha; }

        const UV2F&     uv() const { return m_data.uv; }
        void            set_uv(const UV2F&);
        
        float           u() const { return m_data.uv.u; }
        float           v() const { return m_data.uv.v; }
        
        
        //! Number relevant to the shape (ie, for triangles it's 1...2...3)
        size_t          vertex() const { return m_vertex; }
        void            set_vertex(size_t);

        static void init_meta();

    protected:
        SetVertex³Command(const SetVertex³Command&, const Header&);
        virtual ~SetVertex³Command();
        
    private:
    
        Vertex³     m_data;
        size_t      m_vertex;

        SetVertex³Command(const SetVertex³Command&) = delete;
        SetVertex³Command(SetVertex³Command&&) = delete;
        SetVertex³Command& operator=(const SetVertex³Command&) = delete;
        SetVertex³Command& operator=(SetVertex³Command&&) = delete;
    };
}
