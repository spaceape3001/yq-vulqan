////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MoveByYMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveByʸMCommand)

namespace yq::tachyon {
    MoveByʸMCommand::MoveByʸMCommand(const Header&h) : 
        PositionCommand(h)
    {
    }

    MoveByʸMCommand::MoveByʸMCommand(const Header&h, Meter Δy) : 
        PositionCommand(h), m_Δy(Δy)
    {
    }

    MoveByʸMCommand::MoveByʸMCommand(const MoveByʸMCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_Δy(cp.m_Δy)
    {
    }
    
    MoveByʸMCommand::~MoveByʸMCommand()
    {
    }
    
    PostCPtr    MoveByʸMCommand::clone(rebind_k, const Header& h) const 
    {
        return new MoveByʸMCommand(*this, h);
    }

    void MoveByʸMCommand::init_meta()
    {
        auto w = writer<MoveByʸMCommand>();
        w.description("Position MoveBy Command in Y");
        w.property("Δy", &MoveByʸMCommand::Δy).tag(kTag_Log).tag(kTag_Save);
        w.alias("MoveByY");
    }
}
