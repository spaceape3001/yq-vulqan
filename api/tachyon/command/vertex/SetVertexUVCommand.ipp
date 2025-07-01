////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetVertexUVCommand.hpp"
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetVertexUVCommand)

namespace yq::tachyon {

    SetVertexUVCommand::SetVertexUVCommand(const Header&h, size_t v, const UV2F&coord) : 
        VertexCommand(h), m_uv(coord), m_vertex(v)
    {
    }

    SetVertexUVCommand::SetVertexUVCommand(const SetVertexUVCommand& cp, const Header& h) : 
        VertexCommand(cp, h), m_uv(cp.m_uv), m_vertex(cp.m_vertex)
    {
    }
    
    SetVertexUVCommand::~SetVertexUVCommand()
    {
    }

    PostCPtr    SetVertexUVCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetVertexUVCommand(*this, h);
    }
    
    void        SetVertexUVCommand::set_uv(const UV2F&v)
    {
        m_uv    = v;
    }

    void        SetVertexUVCommand::set_vertex(size_t n)
    {
        m_vertex = n;
    }

    ////////////////////////////////////////////////////////////////////////////

    void SetVertexUVCommand::init_info()
    {
        auto w = writer<SetVertexUVCommand>();
        w.description("Set Vertex UV Command");
        w.property("vertex", &SetVertexUVCommand::m_vertex).tag(kTag_Save).tag(kTag_Log);
        w.property("uv", &SetVertexUVCommand::m_uv).tag(kTag_Save);
        w.property("u", &SetVertexUVCommand::u).tag(kTag_Log);
        w.property("v", &SetVertexUVCommand::v).tag(kTag_Log);
    }
}
