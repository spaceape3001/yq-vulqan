////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMassGramCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMassGramCommand)

namespace yq::tachyon {
    SetMassGramCommand::SetMassGramCommand(const Header&h, unit::Gram kg) : 
        MassCommand(h), m_mass(kg)
    {
    }

    SetMassGramCommand::SetMassGramCommand(const SetMassGramCommand& cp, const Header& h) : 
        MassCommand(cp, h), m_mass(cp.m_mass)
    {
    }
    
    SetMassGramCommand::SetMassGramCommand(const Header&h) : MassCommand(h)
    {
    }

    SetMassGramCommand::~SetMassGramCommand()
    {
    }
    
    PostCPtr    SetMassGramCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMassGramCommand(*this, h);
    }

    void SetMassGramCommand::init_meta()
    {
        auto w = writer<SetMassGramCommand>();
        w.description("Set Mass (Gram) Command");
        w.property("mass", &SetMassGramCommand::m_mass).tag(kTag_Log).tag(kTag_Save);
    }
}
