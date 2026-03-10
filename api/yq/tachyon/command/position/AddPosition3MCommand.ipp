////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddPosition3MCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddPosition3MCommand)

namespace yq::tachyon {
    AddPosition3MCommand::AddPosition3MCommand(const Header&h) : 
        PositionCommand(h)
    {
    }

    AddPosition3MCommand::AddPosition3MCommand(const Header&h, const Meter3D& Δ) : 
        PositionCommand(h), m_Δ(Δ)
    {
    }
    
    AddPosition3MCommand::AddPosition3MCommand(const AddPosition3MCommand&cp, const Header&h) : 
        PositionCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    AddPosition3MCommand::~AddPosition3MCommand()
    {
    }

    PostCPtr    AddPosition3MCommand::clone(rebind_k, const Header& h) const 
    {
        return new AddPosition3MCommand(*this, h);
    }
   
    void AddPosition3MCommand::init_meta()
    {
        auto w = writer<AddPosition3MCommand>();
        w.description("Add Position Command in 3D (meters)");
        w.property("Δx", &AddPosition3MCommand::Δx).tag(kTag_Log);
        w.property("Δy", &AddPosition3MCommand::Δy).tag(kTag_Log);
        w.property("Δz", &AddPosition3MCommand::Δz).tag(kTag_Log);
        w.property("Δ", &AddPosition3MCommand::m_Δ).tag(kTag_Save);
    }
}
