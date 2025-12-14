////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMeshUrlCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMeshUrlCommand)

namespace yq::tachyon {

    SetMeshUrlCommand::SetMeshUrlCommand(const Header&h, const Url& dm) : MeshCommand(h), m_url(dm)
    {
    }

    SetMeshUrlCommand::SetMeshUrlCommand(const SetMeshUrlCommand& cp, const Header& h) : 
        MeshCommand(cp, h), m_url(cp.m_url)
    {
    }
    
    SetMeshUrlCommand::~SetMeshUrlCommand()
    {
    }

    PostCPtr    SetMeshUrlCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMeshUrlCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void SetMeshUrlCommand::init_meta()
    {
        auto w = writer<SetMeshUrlCommand>();
        w.description("Set Mesh Url Command");
        w.property("url", &SetMeshUrlCommand::m_url);
    }
}
