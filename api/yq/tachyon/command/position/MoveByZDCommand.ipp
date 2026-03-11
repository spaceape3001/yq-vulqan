////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MoveByZDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveByᶻDCommand)

namespace yq::tachyon {
    MoveByᶻDCommand::MoveByᶻDCommand(const Header&h) : 
        PositionCommand(h)
    {
    }
    
    MoveByᶻDCommand::MoveByᶻDCommand(const Header&h, double Δz) : 
        PositionCommand(h), m_Δz(Δz)
    {
    }

    MoveByᶻDCommand::MoveByᶻDCommand(const MoveByᶻDCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_Δz(cp.m_Δz)
    {
    }

    MoveByᶻDCommand::~MoveByᶻDCommand()
    {
    }
    
    PostCPtr    MoveByᶻDCommand::clone(rebind_k, const Header&h) const 
    {
        return new MoveByᶻDCommand(*this, h);
    }

    void MoveByᶻDCommand::init_meta()
    {
        auto w = writer<MoveByᶻDCommand>();
        w.description("Position MoveBy Command in Z");
        w.property("Δz", &MoveByᶻDCommand::Δz).tag(kTag_Log).tag(kTag_Save);
    }
}
