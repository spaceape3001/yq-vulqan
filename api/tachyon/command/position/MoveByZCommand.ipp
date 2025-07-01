////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/position/MoveByZCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveByᶻCommand)

namespace yq::tachyon {
    MoveByᶻCommand::MoveByᶻCommand(const Header&h) : 
        PositionCommand(h)
    {
    }
    
    MoveByᶻCommand::MoveByᶻCommand(const Header&h, double Δz) : 
        PositionCommand(h), m_Δz(Δz)
    {
    }

    MoveByᶻCommand::MoveByᶻCommand(const MoveByᶻCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_Δz(cp.m_Δz)
    {
    }

    MoveByᶻCommand::~MoveByᶻCommand()
    {
    }
    
    PostCPtr    MoveByᶻCommand::clone(rebind_k, const Header&h) const 
    {
        return new MoveByᶻCommand(*this, h);
    }

    void MoveByᶻCommand::init_info()
    {
        auto w = writer<MoveByᶻCommand>();
        w.description("Position MoveBy Command in Z");
        w.property("Δz", &MoveByᶻCommand::Δz).tag(kTag_Log).tag(kTag_Save);
    }
}
