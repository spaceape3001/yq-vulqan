////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MoveByWCMCommand.hpp"
#include <yq/tachyon/tags.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveByʷCMCommand)

namespace yq::tachyon {
    MoveByʷCMCommand::MoveByʷCMCommand(const Header&h) : 
        PositionCommand(h)
    {
    }

    MoveByʷCMCommand::MoveByʷCMCommand(const Header&h, Centimeter Δw) : 
        PositionCommand(h), m_Δw(Δw)
    {
    }
    
    MoveByʷCMCommand::MoveByʷCMCommand(const MoveByʷCMCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_Δw(cp.m_Δw)
    {
    }

    MoveByʷCMCommand::~MoveByʷCMCommand()
    {
    }
    
    PostCPtr    MoveByʷCMCommand::clone(rebind_k, const Header&h) const 
    {
        return new MoveByʷCMCommand(*this, h);
    }

    void MoveByʷCMCommand::init_meta()
    {
        auto w = writer<MoveByʷCMCommand>();
        w.description("Position MoveBy Command in X");
        w.property("Δw", &MoveByʷCMCommand::Δw).tag(kTag_Log).tag(kTag_Save);
    }
}
