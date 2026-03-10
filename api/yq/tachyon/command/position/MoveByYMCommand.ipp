////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MoveByYMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveByYMCommand)

namespace yq::tachyon {
    MoveByYMCommand::MoveByYMCommand(const Header&h) : 
        PositionCommand(h)
    {
    }

    MoveByYMCommand::MoveByYMCommand(const Header&h, Meter Δy) : 
        PositionCommand(h), m_Δy(Δy)
    {
    }

    MoveByYMCommand::MoveByYMCommand(const MoveByYMCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_Δy(cp.m_Δy)
    {
    }
    
    MoveByYMCommand::~MoveByYMCommand()
    {
    }
    
    PostCPtr    MoveByYMCommand::clone(rebind_k, const Header& h) const 
    {
        return new MoveByYMCommand(*this, h);
    }

    void MoveByYMCommand::init_meta()
    {
        auto w = writer<MoveByYMCommand>();
        w.description("Position MoveBy Command in Y");
        w.property("Δy", &MoveByYMCommand::Δy).tag(kTag_Log).tag(kTag_Save);
        w.alias("MoveByY");
    }
}
