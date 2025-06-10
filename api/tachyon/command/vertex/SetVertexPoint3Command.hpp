////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/VertexCommand.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {
    class SetVertexPoint³Command : public VertexCommand {
        YQ_OBJECT_DECLARE(SetVertexPoint³Command, VertexCommand)
    public:
        SetVertexPoint³Command(const Header&, size_t, const Vector3D&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        const Vector3D& point() const { return m_point; }
        double          x() const { return m_point.x; }
        double          y() const { return m_point.y; }
        double          z() const { return m_point.z; }
        
        void            set_point(const Vector3D&);
        
        //! Number relevant to the shape (ie, for triangles it's 1...2...3)
        size_t          vertex() const { return m_vertex; }
        void            set_vertex(size_t);

        static void init_info();

    protected:
        SetVertexPoint³Command(const SetVertexPoint³Command&, const Header&);
        virtual ~SetVertexPoint³Command();
        
    private:
    
        Vector3D    m_point;
        size_t      m_vertex;

        SetVertexPoint³Command(const SetVertexPoint³Command&) = delete;
        SetVertexPoint³Command(SetVertexPoint³Command&&) = delete;
        SetVertexPoint³Command& operator=(const SetVertexPoint³Command&) = delete;
        SetVertexPoint³Command& operator=(SetVertexPoint³Command&&) = delete;
    };
}
