////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/position/MoveByWCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveByʷCommand)

namespace yq::tachyon {
    MoveByʷCommand::MoveByʷCommand(const Header&h) : 
        PositionCommand(h)
    {
    }

    MoveByʷCommand::MoveByʷCommand(const Header&h, double Δw) : 
        PositionCommand(h), m_Δw(Δw)
    {
    }
    
    MoveByʷCommand::MoveByʷCommand(const MoveByʷCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_Δw(cp.m_Δw)
    {
    }

    MoveByʷCommand::~MoveByʷCommand()
    {
    }
    
    PostCPtr    MoveByʷCommand::clone(rebind_k, const Header&h) const 
    {
        return new MoveByʷCommand(*this, h);
    }

    void MoveByʷCommand::init_info()
    {
        auto w = writer<MoveByʷCommand>();
        w.description("Position MoveBy Command in X");
        w.property("Δw", &MoveByʷCommand::Δw).tag(kTag_Log).tag(kTag_Save);
    }
}
