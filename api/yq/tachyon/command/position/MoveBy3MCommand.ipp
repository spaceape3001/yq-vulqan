////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MoveBy3MCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveBy3MCommand)

namespace yq::tachyon {
    MoveBy3MCommand::MoveBy3MCommand(const Header&h) : 
        PositionCommand(h)
    {
    }

    MoveBy3MCommand::MoveBy3MCommand(const Header&h, const Meter3D& Δ) : 
        PositionCommand(h), m_Δ(Δ)
    {
    }
    
    MoveBy3MCommand::MoveBy3MCommand(const MoveBy3MCommand&cp, const Header&h) : 
        PositionCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    MoveBy3MCommand::~MoveBy3MCommand()
    {
    }

    PostCPtr    MoveBy3MCommand::clone(rebind_k, const Header& h) const 
    {
        return new MoveBy3MCommand(*this, h);
    }
   
    void MoveBy3MCommand::init_meta()
    {
        auto w = writer<MoveBy3MCommand>();
        w.description("Position MoveBy Command in 3D (meters)");
        w.property("Δx", &MoveBy3MCommand::Δx).tag(kTag_Log);
        w.property("Δy", &MoveBy3MCommand::Δy).tag(kTag_Log);
        w.property("Δz", &MoveBy3MCommand::Δz).tag(kTag_Log);
        w.property("Δ", &MoveBy3MCommand::m_Δ).tag(kTag_Save);
    }
}
