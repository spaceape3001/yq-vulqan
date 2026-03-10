////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMassKGCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMassKGCommand)

namespace yq::tachyon {
    SetMassKGCommand::SetMassKGCommand(const Header&h, Kilogram kg) : 
        MassCommand(h), m_mass(kg)
    {
    }

    SetMassKGCommand::SetMassKGCommand(const SetMassKGCommand& cp, const Header& h) : 
        MassCommand(cp, h), m_mass(cp.m_mass)
    {
    }
    
    SetMassKGCommand::SetMassKGCommand(const Header&h) : MassCommand(h)
    {
    }

    SetMassKGCommand::~SetMassKGCommand()
    {
    }
    
    PostCPtr    SetMassKGCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMassKGCommand(*this, h);
    }

    void SetMassKGCommand::init_meta()
    {
        auto w = writer<SetMassKGCommand>();
        w.description("Set Mass (KG) Command");
        w.property("mass", &SetMassKGCommand::m_mass).tag(kTag_Log).tag(kTag_Save);
    }
}
