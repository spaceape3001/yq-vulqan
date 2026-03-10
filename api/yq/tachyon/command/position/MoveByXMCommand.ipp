////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MoveByXMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveByXMCommand)

namespace yq::tachyon {
    MoveByXMCommand::MoveByXMCommand(const Header&h) : 
        PositionCommand(h)
    {
    }

    MoveByXMCommand::MoveByXMCommand(const Header&h, Meter Δx) : 
        PositionCommand(h), m_Δx(Δx)
    {
    }
    
    MoveByXMCommand::MoveByXMCommand(const MoveByXMCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_Δx(cp.m_Δx)
    {
    }

    MoveByXMCommand::~MoveByXMCommand()
    {
    }
    
    PostCPtr    MoveByXMCommand::clone(rebind_k, const Header&h) const 
    {
        return new MoveByXMCommand(*this, h);
    }

    void MoveByXMCommand::init_meta()
    {
        auto w = writer<MoveByXMCommand>();
        w.description("Position MoveBy Command in X");
        w.property("Δx", &MoveByXMCommand::Δx).tag(kTag_Log).tag(kTag_Save);
        w.alias("MoveByX");
    }
}
