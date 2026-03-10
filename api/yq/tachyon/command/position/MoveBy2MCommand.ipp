////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MoveBy2MCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveBy2MCommand)

namespace yq::tachyon {
    MoveBy2MCommand::MoveBy2MCommand(const Header&h) : 
        PositionCommand(h)
    {
    }
    
    MoveBy2MCommand::MoveBy2MCommand(const Header&h, const Meter2D& Δ) : 
        PositionCommand(h), m_Δ(Δ)
    {
    }

    MoveBy2MCommand::MoveBy2MCommand(const MoveBy2MCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    MoveBy2MCommand::~MoveBy2MCommand()
    {
    }
    
    PostCPtr    MoveBy2MCommand::clone(rebind_k, const Header& h) const 
    {
        return new MoveBy2MCommand(*this, h);
    }

    void MoveBy2MCommand::init_meta()
    {
        auto w = writer<MoveBy2MCommand>();
        w.description("Position MoveBy Command in 2D");
        w.property("Δx", &MoveBy2MCommand::Δx).tag(kTag_Log);
        w.property("Δy", &MoveBy2MCommand::Δy).tag(kTag_Log);
        w.property("Δ", &MoveBy2MCommand::m_Δ).tag(kTag_Save);
    }
}
