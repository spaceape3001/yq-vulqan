////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MoveBy4MCommand.hpp"
#include <yq/tachyon/tags.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveBy⁴MCommand)

namespace yq::tachyon {
    MoveBy⁴MCommand::MoveBy⁴MCommand(const Header&h) : 
        PositionCommand(h)
    {
    }

    MoveBy⁴MCommand::MoveBy⁴MCommand(const Header&h, const Meter4D& Δ) : 
        PositionCommand(h), m_Δ(Δ)
    {
    }
    
    MoveBy⁴MCommand::MoveBy⁴MCommand(const MoveBy⁴MCommand&cp, const Header&h) : 
        PositionCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    MoveBy⁴MCommand::~MoveBy⁴MCommand()
    {
    }

    PostCPtr    MoveBy⁴MCommand::clone(rebind_k, const Header& h) const 
    {
        return new MoveBy⁴MCommand(*this, h);
    }
   
    void MoveBy⁴MCommand::init_meta()
    {
        auto w = writer<MoveBy⁴MCommand>();
        w.description("Position MoveBy Command in 4D");
        w.property("Δw", &MoveBy⁴MCommand::Δw).tag(kTag_Log);
        w.property("Δx", &MoveBy⁴MCommand::Δx).tag(kTag_Log);
        w.property("Δy", &MoveBy⁴MCommand::Δy).tag(kTag_Log);
        w.property("Δz", &MoveBy⁴MCommand::Δz).tag(kTag_Log);
        w.property("Δ", &MoveBy⁴MCommand::m_Δ).tag(kTag_Save);
    }
}
