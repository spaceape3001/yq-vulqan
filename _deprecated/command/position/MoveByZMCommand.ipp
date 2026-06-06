////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MoveByZMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveByᶻMCommand)

namespace yq::tachyon {
    MoveByᶻMCommand::MoveByᶻMCommand(const Header&h) : 
        PositionCommand(h)
    {
    }
    
    MoveByᶻMCommand::MoveByᶻMCommand(const Header&h, Meter Δz) : 
        PositionCommand(h), m_Δz(Δz)
    {
    }

    MoveByᶻMCommand::MoveByᶻMCommand(const MoveByᶻMCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_Δz(cp.m_Δz)
    {
    }

    MoveByᶻMCommand::~MoveByᶻMCommand()
    {
    }
    
    PostCPtr    MoveByᶻMCommand::clone(rebind_k, const Header&h) const 
    {
        return new MoveByᶻMCommand(*this, h);
    }

    void MoveByᶻMCommand::init_meta()
    {
        auto w = writer<MoveByᶻMCommand>();
        w.description("Position MoveBy Command in Z");
        w.property("Δz", &MoveByᶻMCommand::Δz).tag(kTag_Log).tag(kTag_Save);
    }
}
