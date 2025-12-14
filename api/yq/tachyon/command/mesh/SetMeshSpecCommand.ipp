////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMeshSpecCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMeshSpecCommand)

namespace yq::tachyon {

    SetMeshSpecCommand::SetMeshSpecCommand(const Header&h, const std::string& dm) : MeshCommand(h), m_spec(dm)
    {
    }

    SetMeshSpecCommand::SetMeshSpecCommand(const SetMeshSpecCommand& cp, const Header& h) : 
        MeshCommand(cp, h), m_spec(cp.m_spec)
    {
    }
    
    SetMeshSpecCommand::~SetMeshSpecCommand()
    {
    }

    PostCPtr    SetMeshSpecCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMeshSpecCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void SetMeshSpecCommand::init_meta()
    {
        auto w = writer<SetMeshSpecCommand>();
        w.description("Set Height Field Spec Command");
        w.property("spec", &SetMeshSpecCommand::m_spec);
    }
}
