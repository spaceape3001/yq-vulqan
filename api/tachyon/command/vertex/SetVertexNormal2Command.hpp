////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/VertexCommand.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {
    class SetVertexNormal²Command : public VertexCommand {
        YQ_OBJECT_DECLARE(SetVertexNormal²Command, VertexCommand)
    public:
        SetVertexNormal²Command(const Header&, size_t, const Vector2F&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        const Vector2F& normal() const { return m_normal; }
        float           nx() const { return m_normal.x; }
        float           ny() const { return m_normal.y; }
        
        void            set_normal(const Vector2F&);
        
        //! Number relevant to the shape (ie, for triangles it's 1...2...2)
        size_t          vertex() const { return m_vertex; }
        void            set_vertex(size_t);

        static void init_info();

    protected:
        SetVertexNormal²Command(const SetVertexNormal²Command&, const Header&);
        virtual ~SetVertexNormal²Command();
        
    private:
    
        Vector2F    m_normal;
        size_t      m_vertex;

        SetVertexNormal²Command(const SetVertexNormal²Command&) = delete;
        SetVertexNormal²Command(SetVertexNormal²Command&&) = delete;
        SetVertexNormal²Command& operator=(const SetVertexNormal²Command&) = delete;
        SetVertexNormal²Command& operator=(SetVertexNormal²Command&&) = delete;
    };
}
