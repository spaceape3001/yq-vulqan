////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MoveBy3CMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveBy³CMCommand)

namespace yq::tachyon {
    MoveBy³CMCommand::MoveBy³CMCommand(const Header&h) : 
        PositionCommand(h)
    {
    }

    MoveBy³CMCommand::MoveBy³CMCommand(const Header&h, const Centimeter3D& Δ) : 
        PositionCommand(h), m_Δ(Δ)
    {
    }
    
    MoveBy³CMCommand::MoveBy³CMCommand(const MoveBy³CMCommand&cp, const Header&h) : 
        PositionCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    MoveBy³CMCommand::~MoveBy³CMCommand()
    {
    }

    PostCPtr    MoveBy³CMCommand::clone(rebind_k, const Header& h) const 
    {
        return new MoveBy³CMCommand(*this, h);
    }
   
    void MoveBy³CMCommand::init_meta()
    {
        auto w = writer<MoveBy³CMCommand>();
        w.description("Position MoveBy Command in 3D (meters)");
        w.property("Δx", &MoveBy³CMCommand::Δx).tag(kTag_Log);
        w.property("Δy", &MoveBy³CMCommand::Δy).tag(kTag_Log);
        w.property("Δz", &MoveBy³CMCommand::Δz).tag(kTag_Log);
        w.property("Δ", &MoveBy³CMCommand::m_Δ).tag(kTag_Save);
    }
}
