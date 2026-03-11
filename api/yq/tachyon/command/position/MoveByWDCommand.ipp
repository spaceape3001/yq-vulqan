////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MoveByWDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveByʷDCommand)

namespace yq::tachyon {
    MoveByʷDCommand::MoveByʷDCommand(const Header&h) : 
        PositionCommand(h)
    {
    }

    MoveByʷDCommand::MoveByʷDCommand(const Header&h, double Δw) : 
        PositionCommand(h), m_Δw(Δw)
    {
    }
    
    MoveByʷDCommand::MoveByʷDCommand(const MoveByʷDCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_Δw(cp.m_Δw)
    {
    }

    MoveByʷDCommand::~MoveByʷDCommand()
    {
    }
    
    PostCPtr    MoveByʷDCommand::clone(rebind_k, const Header&h) const 
    {
        return new MoveByʷDCommand(*this, h);
    }

    void MoveByʷDCommand::init_meta()
    {
        auto w = writer<MoveByʷDCommand>();
        w.description("Position MoveBy Command in X");
        w.property("Δw", &MoveByʷDCommand::Δw).tag(kTag_Log).tag(kTag_Save);
    }
}
