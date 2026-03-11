////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MoveBy2DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveBy²DCommand)

namespace yq::tachyon {
    MoveBy²DCommand::MoveBy²DCommand(const Header&h) : 
        PositionCommand(h)
    {
    }
    
    MoveBy²DCommand::MoveBy²DCommand(const Header&h, const Vector2D& Δ) : 
        PositionCommand(h), m_Δ(Δ)
    {
    }

    MoveBy²DCommand::MoveBy²DCommand(const MoveBy²DCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    MoveBy²DCommand::~MoveBy²DCommand()
    {
    }
    
    PostCPtr    MoveBy²DCommand::clone(rebind_k, const Header& h) const 
    {
        return new MoveBy²DCommand(*this, h);
    }

    void MoveBy²DCommand::init_meta()
    {
        auto w = writer<MoveBy²DCommand>();
        w.description("Position MoveBy Command in 2D");
        w.property("Δx", &MoveBy²DCommand::Δx).tag(kTag_Log);
        w.property("Δy", &MoveBy²DCommand::Δy).tag(kTag_Log);
        w.property("Δ", &MoveBy²DCommand::m_Δ).tag(kTag_Save);
    }
}
