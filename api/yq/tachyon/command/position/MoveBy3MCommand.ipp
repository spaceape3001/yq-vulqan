////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MoveBy3MCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveBy³MCommand)

namespace yq::tachyon {
    MoveBy³MCommand::MoveBy³MCommand(const Header&h) : 
        PositionCommand(h)
    {
    }

    MoveBy³MCommand::MoveBy³MCommand(const Header&h, const Meter3D& Δ) : 
        PositionCommand(h), m_Δ(Δ)
    {
    }
    
    MoveBy³MCommand::MoveBy³MCommand(const MoveBy³MCommand&cp, const Header&h) : 
        PositionCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    MoveBy³MCommand::~MoveBy³MCommand()
    {
    }

    PostCPtr    MoveBy³MCommand::clone(rebind_k, const Header& h) const 
    {
        return new MoveBy³MCommand(*this, h);
    }
   
    void MoveBy³MCommand::init_meta()
    {
        auto w = writer<MoveBy³MCommand>();
        w.description("Position MoveBy Command in 3D (meters)");
        w.property("Δx", &MoveBy³MCommand::Δx).tag(kTag_Log);
        w.property("Δy", &MoveBy³MCommand::Δy).tag(kTag_Log);
        w.property("Δz", &MoveBy³MCommand::Δz).tag(kTag_Log);
        w.property("Δ", &MoveBy³MCommand::m_Δ).tag(kTag_Save);
    }
}
