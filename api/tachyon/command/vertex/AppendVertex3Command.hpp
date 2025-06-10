////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/VertexCommand.hpp>
#include <tachyon/data/Vertex3.hpp>

namespace yq::tachyon {
    class AppendVertex³Command : public VertexCommand {
        YQ_OBJECT_DECLARE(AppendVertex³Command, VertexCommand)
    public:
        AppendVertex³Command(const Header&, const Vertex³&);
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

        static void init_info();

    protected:
        AppendVertex³Command(const AppendVertex³Command&, const Header&);
        virtual ~AppendVertex³Command();
        
    private:
    
        Vertex³     m_data;

        AppendVertex³Command(const AppendVertex³Command&) = delete;
        AppendVertex³Command(AppendVertex³Command&&) = delete;
        AppendVertex³Command& operator=(const AppendVertex³Command&) = delete;
        AppendVertex³Command& operator=(AppendVertex³Command&&) = delete;
    };
}
