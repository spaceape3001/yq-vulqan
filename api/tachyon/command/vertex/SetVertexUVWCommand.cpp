////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetVertexUVWCommand.hpp"
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetVertexUVWCommand)

namespace yq::tachyon {

    SetVertexUVWCommand::SetVertexUVWCommand(const Header&h, size_t v, const UVW3F&coord) : 
        VertexCommand(h), m_uvw(coord), m_vertex(v)
    {
    }

    SetVertexUVWCommand::SetVertexUVWCommand(const SetVertexUVWCommand& cp, const Header& h) : 
        VertexCommand(cp, h), m_uvw(cp.m_uvw), m_vertex(cp.m_vertex)
    {
    }
    
    SetVertexUVWCommand::~SetVertexUVWCommand()
    {
    }

    PostCPtr    SetVertexUVWCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetVertexUVWCommand(*this, h);
    }
    
    void        SetVertexUVWCommand::set_uvw(const UVW3F&v)
    {
        m_uvw    = v;
    }

    void        SetVertexUVWCommand::set_vertex(size_t n)
    {
        m_vertex = n;
    }

    ////////////////////////////////////////////////////////////////////////////

    void SetVertexUVWCommand::init_info()
    {
        auto w = writer<SetVertexUVWCommand>();
        w.description("Set Vertex UVW Command");
        w.property("vertex", &SetVertexUVWCommand::m_vertex).tag(kTag_Save).tag(kTag_Log);
        w.property("uvw", &SetVertexUVWCommand::m_uvw).tag(kTag_Save);
        w.property("u", &SetVertexUVWCommand::u).tag(kTag_Log);
        w.property("v", &SetVertexUVWCommand::v).tag(kTag_Log);
        w.property("w", &SetVertexUVWCommand::w).tag(kTag_Log);
    }
}
