////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MoveByZCMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveByᶻCMCommand)

namespace yq::tachyon {
    MoveByᶻCMCommand::MoveByᶻCMCommand(const Header&h) : 
        PositionCommand(h)
    {
    }
    
    MoveByᶻCMCommand::MoveByᶻCMCommand(const Header&h, Centimeter Δz) : 
        PositionCommand(h), m_Δz(Δz)
    {
    }

    MoveByᶻCMCommand::MoveByᶻCMCommand(const MoveByᶻCMCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_Δz(cp.m_Δz)
    {
    }

    MoveByᶻCMCommand::~MoveByᶻCMCommand()
    {
    }
    
    PostCPtr    MoveByᶻCMCommand::clone(rebind_k, const Header&h) const 
    {
        return new MoveByᶻCMCommand(*this, h);
    }

    void MoveByᶻCMCommand::init_meta()
    {
        auto w = writer<MoveByᶻCMCommand>();
        w.description("Position MoveBy Command in Z");
        w.property("Δz", &MoveByᶻCMCommand::Δz).tag(kTag_Log).tag(kTag_Save);
    }
}
