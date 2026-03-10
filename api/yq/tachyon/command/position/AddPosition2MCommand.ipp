////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddPosition2MCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddPosition2MCommand)

namespace yq::tachyon {
    AddPosition2MCommand::AddPosition2MCommand(const Header&h) : 
        PositionCommand(h)
    {
    }
    
    AddPosition2MCommand::AddPosition2MCommand(const Header&h, const Meter2D& Δ) : 
        PositionCommand(h), m_Δ(Δ)
    {
    }

    AddPosition2MCommand::AddPosition2MCommand(const AddPosition2MCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    AddPosition2MCommand::~AddPosition2MCommand()
    {
    }
    
    PostCPtr    AddPosition2MCommand::clone(rebind_k, const Header& h) const 
    {
        return new AddPosition2MCommand(*this, h);
    }

    void AddPosition2MCommand::init_meta()
    {
        auto w = writer<AddPosition2MCommand>();
        w.description("Add Position Command in 2D (meters)");
        w.property("Δx", &AddPosition2MCommand::Δx).tag(kTag_Log);
        w.property("Δy", &AddPosition2MCommand::Δy).tag(kTag_Log);
        w.property("Δ", &AddPosition2MCommand::m_Δ).tag(kTag_Save);
    }
}
