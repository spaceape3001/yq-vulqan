////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MoveBy4CMCommand.hpp"
#include <yq/tachyon/tags.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveBy⁴CMCommand)

namespace yq::tachyon {
    MoveBy⁴CMCommand::MoveBy⁴CMCommand(const Header&h) : 
        PositionCommand(h)
    {
    }

    MoveBy⁴CMCommand::MoveBy⁴CMCommand(const Header&h, const Centimeter4D& Δ) : 
        PositionCommand(h), m_Δ(Δ)
    {
    }
    
    MoveBy⁴CMCommand::MoveBy⁴CMCommand(const MoveBy⁴CMCommand&cp, const Header&h) : 
        PositionCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    MoveBy⁴CMCommand::~MoveBy⁴CMCommand()
    {
    }

    PostCPtr    MoveBy⁴CMCommand::clone(rebind_k, const Header& h) const 
    {
        return new MoveBy⁴CMCommand(*this, h);
    }
   
    void MoveBy⁴CMCommand::init_meta()
    {
        auto w = writer<MoveBy⁴CMCommand>();
        w.description("Position MoveBy Command in 4D");
        w.property("Δw", &MoveBy⁴CMCommand::Δw).tag(kTag_Log);
        w.property("Δx", &MoveBy⁴CMCommand::Δx).tag(kTag_Log);
        w.property("Δy", &MoveBy⁴CMCommand::Δy).tag(kTag_Log);
        w.property("Δz", &MoveBy⁴CMCommand::Δz).tag(kTag_Log);
        w.property("Δ", &MoveBy⁴CMCommand::m_Δ).tag(kTag_Save);
    }
}
