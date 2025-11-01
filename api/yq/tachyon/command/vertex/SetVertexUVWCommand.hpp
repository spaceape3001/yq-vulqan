////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/VertexCommand.hpp>
#include <yq/math/UVW.hpp>

namespace yq::tachyon {
    class SetVertexUVWCommand : public VertexCommand {
        YQ_OBJECT_DECLARE(SetVertexUVWCommand, VertexCommand)
    public:
        SetVertexUVWCommand(const Header&, size_t, const UVW3F&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        const UVW3F&    uvw() const { return m_uvw; }
        float           u() const { return m_uvw.u; }
        float           v() const { return m_uvw.v; }
        float           w() const { return m_uvw.w; }
        
        void            set_uvw(const UVW3F&);
        
        //! Number relevant to the shape (ie, for triangles it's 1...2...3)
        size_t          vertex() const { return m_vertex; }
        void            set_vertex(size_t);

        static void init_meta();

    protected:
        SetVertexUVWCommand(const SetVertexUVWCommand&, const Header&);
        virtual ~SetVertexUVWCommand();
        
    private:
    
        UVW3F       m_uvw;
        size_t      m_vertex;

        SetVertexUVWCommand(const SetVertexUVWCommand&) = delete;
        SetVertexUVWCommand(SetVertexUVWCommand&&) = delete;
        SetVertexUVWCommand& operator=(const SetVertexUVWCommand&) = delete;
        SetVertexUVWCommand& operator=(SetVertexUVWCommand&&) = delete;
    };
}
