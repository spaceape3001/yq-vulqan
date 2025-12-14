////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMeshCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>
#include <yq/tachyon/asset/Mesh.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMeshCommand)

namespace yq::tachyon {

    SetMeshCommand::SetMeshCommand(const Header&h, const MeshCPtr& dm) : MeshCommand(h), m_mesh(dm)
    {
    }

    SetMeshCommand::SetMeshCommand(const SetMeshCommand& cp, const Header& h) : 
        MeshCommand(cp, h), m_mesh(cp.m_mesh)
    {
    }
    
    SetMeshCommand::~SetMeshCommand()
    {
    }

    PostCPtr    SetMeshCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMeshCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void SetMeshCommand::init_meta()
    {
        auto w = writer<SetMeshCommand>();
        w.description("Set Mesh Command");
    }
}
