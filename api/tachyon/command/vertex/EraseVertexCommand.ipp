////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "EraseVertexCommand.hpp"
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::EraseVertexCommand)

namespace yq::tachyon {

    EraseVertexCommand::EraseVertexCommand(const Header&h, size_t v) : 
        VertexCommand(h), m_vertex(v)
    {
    }

    EraseVertexCommand::EraseVertexCommand(const EraseVertexCommand& cp, const Header& h) : 
        VertexCommand(cp, h), m_vertex(cp.m_vertex)
    {
    }
    
    EraseVertexCommand::~EraseVertexCommand()
    {
    }

    PostCPtr    EraseVertexCommand::clone(rebind_k, const Header&h) const 
    {
        return new EraseVertexCommand(*this, h);
    }
    
    void        EraseVertexCommand::set_vertex(size_t n)
    {
        m_vertex = n;
    }

    ////////////////////////////////////////////////////////////////////////////

    void EraseVertexCommand::init_info()
    {
        auto w = writer<EraseVertexCommand>();
        w.description("Erase Vertex 3D Command");

        w.property("vertex", &EraseVertexCommand::m_vertex).tag(kTag_Save).tag(kTag_Log);
    }
}
