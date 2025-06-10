////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/VertexCommand.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {
    class SetVertexNormal³Command : public VertexCommand {
        YQ_OBJECT_DECLARE(SetVertexNormal³Command, VertexCommand)
    public:
        SetVertexNormal³Command(const Header&, size_t, const Vector3F&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        const Vector3F& normal() const { return m_normal; }
        float           nx() const { return m_normal.x; }
        float           ny() const { return m_normal.y; }
        float           nz() const { return m_normal.z; }
        
        void            set_normal(const Vector3F&);
        
        //! Number relevant to the shape (ie, for triangles it's 1...2...3)
        size_t          vertex() const { return m_vertex; }
        void            set_vertex(size_t);

        static void init_info();

    protected:
        SetVertexNormal³Command(const SetVertexNormal³Command&, const Header&);
        virtual ~SetVertexNormal³Command();
        
    private:
    
        Vector3F    m_normal;
        size_t      m_vertex;

        SetVertexNormal³Command(const SetVertexNormal³Command&) = delete;
        SetVertexNormal³Command(SetVertexNormal³Command&&) = delete;
        SetVertexNormal³Command& operator=(const SetVertexNormal³Command&) = delete;
        SetVertexNormal³Command& operator=(SetVertexNormal³Command&&) = delete;
    };
}
