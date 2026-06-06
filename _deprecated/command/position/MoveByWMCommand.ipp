////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MoveByWMCommand.hpp"
#include <yq/tachyon/tags.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveByʷMCommand)

namespace yq::tachyon {
    MoveByʷMCommand::MoveByʷMCommand(const Header&h) : 
        PositionCommand(h)
    {
    }

    MoveByʷMCommand::MoveByʷMCommand(const Header&h, Meter Δw) : 
        PositionCommand(h), m_Δw(Δw)
    {
    }
    
    MoveByʷMCommand::MoveByʷMCommand(const MoveByʷMCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_Δw(cp.m_Δw)
    {
    }

    MoveByʷMCommand::~MoveByʷMCommand()
    {
    }
    
    PostCPtr    MoveByʷMCommand::clone(rebind_k, const Header&h) const 
    {
        return new MoveByʷMCommand(*this, h);
    }

    void MoveByʷMCommand::init_meta()
    {
        auto w = writer<MoveByʷMCommand>();
        w.description("Position MoveBy Command in X");
        w.property("Δw", &MoveByʷMCommand::Δw).tag(kTag_Log).tag(kTag_Save);
    }
}
