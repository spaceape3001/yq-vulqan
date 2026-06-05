////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MoveBy2CMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveBy²CMCommand)

namespace yq::tachyon {
    MoveBy²CMCommand::MoveBy²CMCommand(const Header&h) : 
        PositionCommand(h)
    {
    }
    
    MoveBy²CMCommand::MoveBy²CMCommand(const Header&h, const Centimeter2D& Δ) : 
        PositionCommand(h), m_Δ(Δ)
    {
    }

    MoveBy²CMCommand::MoveBy²CMCommand(const MoveBy²CMCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    MoveBy²CMCommand::~MoveBy²CMCommand()
    {
    }
    
    PostCPtr    MoveBy²CMCommand::clone(rebind_k, const Header& h) const 
    {
        return new MoveBy²CMCommand(*this, h);
    }

    void MoveBy²CMCommand::init_meta()
    {
        auto w = writer<MoveBy²CMCommand>();
        w.description("Position MoveBy Command in 2D");
        w.property("Δx", &MoveBy²CMCommand::Δx).tag(kTag_Log);
        w.property("Δy", &MoveBy²CMCommand::Δy).tag(kTag_Log);
        w.property("Δ", &MoveBy²CMCommand::m_Δ).tag(kTag_Save);
    }
}
