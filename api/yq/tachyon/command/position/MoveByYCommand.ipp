////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MoveByYCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveByʸCommand)

namespace yq::tachyon {
    MoveByʸCommand::MoveByʸCommand(const Header&h) : 
        PositionCommand(h)
    {
    }

    MoveByʸCommand::MoveByʸCommand(const Header&h, double Δy) : 
        PositionCommand(h), m_Δy(Δy)
    {
    }

    MoveByʸCommand::MoveByʸCommand(const MoveByʸCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_Δy(cp.m_Δy)
    {
    }
    
    MoveByʸCommand::~MoveByʸCommand()
    {
    }
    
    PostCPtr    MoveByʸCommand::clone(rebind_k, const Header& h) const 
    {
        return new MoveByʸCommand(*this, h);
    }

    void MoveByʸCommand::init_meta()
    {
        auto w = writer<MoveByʸCommand>();
        w.description("Position MoveBy Command in Y");
        w.property("Δy", &MoveByʸCommand::Δy).tag(kTag_Log).tag(kTag_Save);
        w.alias("MoveByY");
    }
}
