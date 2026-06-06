////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddPosition2MCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddPosition²MCommand)

namespace yq::tachyon {
    AddPosition²MCommand::AddPosition²MCommand(const Header&h) : 
        PositionCommand(h)
    {
    }
    
    AddPosition²MCommand::AddPosition²MCommand(const Header&h, const Meter2D& Δ) : 
        PositionCommand(h), m_Δ(Δ)
    {
    }

    AddPosition²MCommand::AddPosition²MCommand(const AddPosition²MCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    AddPosition²MCommand::~AddPosition²MCommand()
    {
    }
    
    PostCPtr    AddPosition²MCommand::clone(rebind_k, const Header& h) const 
    {
        return new AddPosition²MCommand(*this, h);
    }

    void AddPosition²MCommand::init_meta()
    {
        auto w = writer<AddPosition²MCommand>();
        w.description("Add Position Command in 2D (meters)");
        w.property("Δx", &AddPosition²MCommand::Δx).tag(kTag_Log);
        w.property("Δy", &AddPosition²MCommand::Δy).tag(kTag_Log);
        w.property("Δ", &AddPosition²MCommand::m_Δ).tag(kTag_Save);
    }
}
