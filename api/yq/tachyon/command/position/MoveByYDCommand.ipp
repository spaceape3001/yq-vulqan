////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MoveByYDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveByʸDCommand)

namespace yq::tachyon {
    MoveByʸDCommand::MoveByʸDCommand(const Header&h) : 
        PositionCommand(h)
    {
    }

    MoveByʸDCommand::MoveByʸDCommand(const Header&h, double Δy) : 
        PositionCommand(h), m_Δy(Δy)
    {
    }

    MoveByʸDCommand::MoveByʸDCommand(const MoveByʸDCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_Δy(cp.m_Δy)
    {
    }
    
    MoveByʸDCommand::~MoveByʸDCommand()
    {
    }
    
    PostCPtr    MoveByʸDCommand::clone(rebind_k, const Header& h) const 
    {
        return new MoveByʸDCommand(*this, h);
    }

    void MoveByʸDCommand::init_meta()
    {
        auto w = writer<MoveByʸDCommand>();
        w.description("Position MoveBy Command in Y");
        w.property("Δy", &MoveByʸDCommand::Δy).tag(kTag_Log).tag(kTag_Save);
        w.alias("MoveByY");
    }
}
