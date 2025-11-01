////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/VertexCommand.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {
    class SetVertexPoint²Command : public VertexCommand {
        YQ_OBJECT_DECLARE(SetVertexPoint²Command, VertexCommand)
    public:
        SetVertexPoint²Command(const Header&, size_t, const Vector2D&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        const Vector2D& point() const { return m_point; }
        double          x() const { return m_point.x; }
        double          y() const { return m_point.y; }
        
        void            set_point(const Vector2D&);
        
        //! Number relevant to the shape (ie, for triangles it's 1...2...2)
        size_t          vertex() const { return m_vertex; }
        void            set_vertex(size_t);

        static void init_meta();

    protected:
        SetVertexPoint²Command(const SetVertexPoint²Command&, const Header&);
        virtual ~SetVertexPoint²Command();
        
    private:
    
        Vector2D    m_point;
        size_t      m_vertex;

        SetVertexPoint²Command(const SetVertexPoint²Command&) = delete;
        SetVertexPoint²Command(SetVertexPoint²Command&&) = delete;
        SetVertexPoint²Command& operator=(const SetVertexPoint²Command&) = delete;
        SetVertexPoint²Command& operator=(SetVertexPoint²Command&&) = delete;
    };
}
