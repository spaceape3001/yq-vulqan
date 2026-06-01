////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MoveBy2MCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveBy²MCommand)

namespace yq::tachyon {
    MoveBy²MCommand::MoveBy²MCommand(const Header&h) : 
        PositionCommand(h)
    {
    }
    
    MoveBy²MCommand::MoveBy²MCommand(const Header&h, const Meter2D& Δ) : 
        PositionCommand(h), m_Δ(Δ)
    {
    }

    MoveBy²MCommand::MoveBy²MCommand(const MoveBy²MCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    MoveBy²MCommand::~MoveBy²MCommand()
    {
    }
    
    PostCPtr    MoveBy²MCommand::clone(rebind_k, const Header& h) const 
    {
        return new MoveBy²MCommand(*this, h);
    }

    void MoveBy²MCommand::init_meta()
    {
        auto w = writer<MoveBy²MCommand>();
        w.description("Position MoveBy Command in 2D");
        w.property("Δx", &MoveBy²MCommand::Δx).tag(kTag_Log);
        w.property("Δy", &MoveBy²MCommand::Δy).tag(kTag_Log);
        w.property("Δ", &MoveBy²MCommand::m_Δ).tag(kTag_Save);
    }
}
