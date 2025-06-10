////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/VertexCommand.hpp>
#include <yq/math/UV.hpp>

namespace yq::tachyon {
    class SetVertexUVCommand : public VertexCommand {
        YQ_OBJECT_DECLARE(SetVertexUVCommand, VertexCommand)
    public:
        SetVertexUVCommand(const Header&, size_t, const UV2F&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        const UV2F&     uvw() const { return m_uv; }
        float           u() const { return m_uv.u; }
        float           v() const { return m_uv.v; }
        
        void            set_uv(const UV2F&);
        
        //! Number relevant to the shape (ie, for triangles it's 1...2...3)
        size_t          vertex() const { return m_vertex; }
        void            set_vertex(size_t);

        static void init_info();

    protected:
        SetVertexUVCommand(const SetVertexUVCommand&, const Header&);
        virtual ~SetVertexUVCommand();
        
    private:
    
        UV2F        m_uv;
        size_t      m_vertex;

        SetVertexUVCommand(const SetVertexUVCommand&) = delete;
        SetVertexUVCommand(SetVertexUVCommand&&) = delete;
        SetVertexUVCommand& operator=(const SetVertexUVCommand&) = delete;
        SetVertexUVCommand& operator=(SetVertexUVCommand&&) = delete;
    };
}
