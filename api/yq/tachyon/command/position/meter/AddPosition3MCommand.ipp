////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddPosition3MCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddPosition³MCommand)

namespace yq::tachyon {
    AddPosition³MCommand::AddPosition³MCommand(const Header&h) : 
        PositionCommand(h)
    {
    }

    AddPosition³MCommand::AddPosition³MCommand(const Header&h, const Meter3D& Δ) : 
        PositionCommand(h), m_Δ(Δ)
    {
    }
    
    AddPosition³MCommand::AddPosition³MCommand(const AddPosition³MCommand&cp, const Header&h) : 
        PositionCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    AddPosition³MCommand::~AddPosition³MCommand()
    {
    }

    PostCPtr    AddPosition³MCommand::clone(rebind_k, const Header& h) const 
    {
        return new AddPosition³MCommand(*this, h);
    }
   
    void AddPosition³MCommand::init_meta()
    {
        auto w = writer<AddPosition³MCommand>();
        w.description("Add Position Command in 3D (meters)");
        w.property("Δx", &AddPosition³MCommand::Δx).tag(kTag_Log);
        w.property("Δy", &AddPosition³MCommand::Δy).tag(kTag_Log);
        w.property("Δz", &AddPosition³MCommand::Δz).tag(kTag_Log);
        w.property("Δ", &AddPosition³MCommand::m_Δ).tag(kTag_Save);
    }
}
