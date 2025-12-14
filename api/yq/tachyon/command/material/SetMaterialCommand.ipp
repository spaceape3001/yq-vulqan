////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMaterialCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>
#include <yq/tachyon/asset/Material.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMaterialCommand)

namespace yq::tachyon {

    SetMaterialCommand::SetMaterialCommand(const Header&h, const MaterialCPtr& dm) : MaterialCommand(h), m_material(dm)
    {
    }

    SetMaterialCommand::SetMaterialCommand(const SetMaterialCommand& cp, const Header& h) : 
        MaterialCommand(cp, h), m_material(cp.m_material)
    {
    }
    
    SetMaterialCommand::~SetMaterialCommand()
    {
    }

    PostCPtr    SetMaterialCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMaterialCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void SetMaterialCommand::init_meta()
    {
        auto w = writer<SetMaterialCommand>();
        w.description("Set Material Command");
    }
}
