////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMaterialSpecCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMaterialSpecCommand)

namespace yq::tachyon {

    SetMaterialSpecCommand::SetMaterialSpecCommand(const Header&h, const std::string& dm) : MaterialCommand(h), m_spec(dm)
    {
    }

    SetMaterialSpecCommand::SetMaterialSpecCommand(const SetMaterialSpecCommand& cp, const Header& h) : 
        MaterialCommand(cp, h), m_spec(cp.m_spec)
    {
    }
    
    SetMaterialSpecCommand::~SetMaterialSpecCommand()
    {
    }

    PostCPtr    SetMaterialSpecCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMaterialSpecCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void SetMaterialSpecCommand::init_meta()
    {
        auto w = writer<SetMaterialSpecCommand>();
        w.description("Set Height Field Spec Command");
        w.property("spec", &SetMaterialSpecCommand::m_spec);
    }
}
