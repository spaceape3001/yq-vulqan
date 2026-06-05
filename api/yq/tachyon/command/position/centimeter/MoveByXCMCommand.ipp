////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MoveByXCMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveByˣCMCommand)

namespace yq::tachyon {
    MoveByˣCMCommand::MoveByˣCMCommand(const Header&h) : 
        PositionCommand(h)
    {
    }

    MoveByˣCMCommand::MoveByˣCMCommand(const Header&h, Centimeter Δx) : 
        PositionCommand(h), m_Δx(Δx)
    {
    }
    
    MoveByˣCMCommand::MoveByˣCMCommand(const MoveByˣCMCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_Δx(cp.m_Δx)
    {
    }

    MoveByˣCMCommand::~MoveByˣCMCommand()
    {
    }
    
    PostCPtr    MoveByˣCMCommand::clone(rebind_k, const Header&h) const 
    {
        return new MoveByˣCMCommand(*this, h);
    }

    void MoveByˣCMCommand::init_meta()
    {
        auto w = writer<MoveByˣCMCommand>();
        w.description("Position MoveBy Command in X");
        w.property("Δx", &MoveByˣCMCommand::Δx).tag(kTag_Log).tag(kTag_Save);
        w.alias("MoveByX");
    }
}
