////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MoveBy4DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveBy⁴DCommand)

namespace yq::tachyon {
    MoveBy⁴DCommand::MoveBy⁴DCommand(const Header&h) : 
        PositionCommand(h)
    {
    }

    MoveBy⁴DCommand::MoveBy⁴DCommand(const Header&h, const Vector4D& Δ) : 
        PositionCommand(h), m_Δ(Δ)
    {
    }
    
    MoveBy⁴DCommand::MoveBy⁴DCommand(const MoveBy⁴DCommand&cp, const Header&h) : 
        PositionCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    MoveBy⁴DCommand::~MoveBy⁴DCommand()
    {
    }

    PostCPtr    MoveBy⁴DCommand::clone(rebind_k, const Header& h) const 
    {
        return new MoveBy⁴DCommand(*this, h);
    }
   
    void MoveBy⁴DCommand::init_meta()
    {
        auto w = writer<MoveBy⁴DCommand>();
        w.description("Position MoveBy Command in 4D");
        w.property("Δw", &MoveBy⁴DCommand::Δw).tag(kTag_Log);
        w.property("Δx", &MoveBy⁴DCommand::Δx).tag(kTag_Log);
        w.property("Δy", &MoveBy⁴DCommand::Δy).tag(kTag_Log);
        w.property("Δz", &MoveBy⁴DCommand::Δz).tag(kTag_Log);
        w.property("Δ", &MoveBy⁴DCommand::m_Δ).tag(kTag_Save);
    }
}
