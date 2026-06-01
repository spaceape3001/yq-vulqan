////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MoveByXMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveByˣMCommand)

namespace yq::tachyon {
    MoveByˣMCommand::MoveByˣMCommand(const Header&h) : 
        PositionCommand(h)
    {
    }

    MoveByˣMCommand::MoveByˣMCommand(const Header&h, Meter Δx) : 
        PositionCommand(h), m_Δx(Δx)
    {
    }
    
    MoveByˣMCommand::MoveByˣMCommand(const MoveByˣMCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_Δx(cp.m_Δx)
    {
    }

    MoveByˣMCommand::~MoveByˣMCommand()
    {
    }
    
    PostCPtr    MoveByˣMCommand::clone(rebind_k, const Header&h) const 
    {
        return new MoveByˣMCommand(*this, h);
    }

    void MoveByˣMCommand::init_meta()
    {
        auto w = writer<MoveByˣMCommand>();
        w.description("Position MoveBy Command in X");
        w.property("Δx", &MoveByˣMCommand::Δx).tag(kTag_Log).tag(kTag_Save);
        w.alias("MoveByX");
    }
}
