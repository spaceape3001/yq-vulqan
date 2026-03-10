////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddMassKGCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMassKGCommand)

namespace yq::tachyon {
    AddMassKGCommand::AddMassKGCommand(const Header&h, unit::Kilogram kg) : 
        MassCommand(h), m_Δmass(kg)
    {
    }

    AddMassKGCommand::AddMassKGCommand(const AddMassKGCommand& cp, const Header& h) : 
        MassCommand(cp, h), m_Δmass(cp.m_Δmass)
    {
    }
    
    AddMassKGCommand::AddMassKGCommand(const Header&h) : MassCommand(h)
    {
    }

    AddMassKGCommand::~AddMassKGCommand()
    {
    }
    
    PostCPtr    AddMassKGCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMassKGCommand(*this, h);
    }

    void AddMassKGCommand::init_meta()
    {
        auto w = writer<AddMassKGCommand>();
        w.description("Add Mass (KG) Command");
        w.property("Δmass", &AddMassKGCommand::m_Δmass).tag(kTag_Log).tag(kTag_Save);
    }
}
