////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MoveByZMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveByZMCommand)

namespace yq::tachyon {
    MoveByZMCommand::MoveByZMCommand(const Header&h) : 
        PositionCommand(h)
    {
    }
    
    MoveByZMCommand::MoveByZMCommand(const Header&h, Meter Δz) : 
        PositionCommand(h), m_Δz(Δz)
    {
    }

    MoveByZMCommand::MoveByZMCommand(const MoveByZMCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_Δz(cp.m_Δz)
    {
    }

    MoveByZMCommand::~MoveByZMCommand()
    {
    }
    
    PostCPtr    MoveByZMCommand::clone(rebind_k, const Header&h) const 
    {
        return new MoveByZMCommand(*this, h);
    }

    void MoveByZMCommand::init_meta()
    {
        auto w = writer<MoveByZMCommand>();
        w.description("Position MoveBy Command in Z");
        w.property("Δz", &MoveByZMCommand::Δz).tag(kTag_Log).tag(kTag_Save);
    }
}
