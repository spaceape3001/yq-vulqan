////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddMassGramCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMassGramCommand)

namespace yq::tachyon {
    AddMassGramCommand::AddMassGramCommand(const Header&h, unit::Gram kg) : 
        MassCommand(h), m_Δmass(kg)
    {
    }

    AddMassGramCommand::AddMassGramCommand(const AddMassGramCommand& cp, const Header& h) : 
        MassCommand(cp, h), m_Δmass(cp.m_Δmass)
    {
    }
    
    AddMassGramCommand::AddMassGramCommand(const Header&h) : MassCommand(h)
    {
    }

    AddMassGramCommand::~AddMassGramCommand()
    {
    }
    
    PostCPtr    AddMassGramCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMassGramCommand(*this, h);
    }

    void AddMassGramCommand::init_meta()
    {
        auto w = writer<AddMassGramCommand>();
        w.description("Add Mass (Gram) Command");
        w.property("Δmass", &AddMassGramCommand::m_Δmass).tag(kTag_Log).tag(kTag_Save);
    }
}
