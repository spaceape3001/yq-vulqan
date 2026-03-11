////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MoveBy3DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveBy³DCommand)

namespace yq::tachyon {
    MoveBy³DCommand::MoveBy³DCommand(const Header&h) : 
        PositionCommand(h)
    {
    }

    MoveBy³DCommand::MoveBy³DCommand(const Header&h, const Vector3D& Δ) : 
        PositionCommand(h), m_Δ(Δ)
    {
    }
    
    MoveBy³DCommand::MoveBy³DCommand(const MoveBy³DCommand&cp, const Header&h) : 
        PositionCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    MoveBy³DCommand::~MoveBy³DCommand()
    {
    }

    PostCPtr    MoveBy³DCommand::clone(rebind_k, const Header& h) const 
    {
        return new MoveBy³DCommand(*this, h);
    }
   
    void MoveBy³DCommand::init_meta()
    {
        auto w = writer<MoveBy³DCommand>();
        w.description("Position MoveBy Command in 3D");
        w.property("Δx", &MoveBy³DCommand::Δx).tag(kTag_Log);
        w.property("Δy", &MoveBy³DCommand::Δy).tag(kTag_Log);
        w.property("Δz", &MoveBy³DCommand::Δz).tag(kTag_Log);
        w.property("Δ", &MoveBy³DCommand::m_Δ).tag(kTag_Save);
    }
}
