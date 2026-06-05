////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MoveByYCMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveByʸCMCommand)

namespace yq::tachyon {
    MoveByʸCMCommand::MoveByʸCMCommand(const Header&h) : 
        PositionCommand(h)
    {
    }

    MoveByʸCMCommand::MoveByʸCMCommand(const Header&h, Centimeter Δy) : 
        PositionCommand(h), m_Δy(Δy)
    {
    }

    MoveByʸCMCommand::MoveByʸCMCommand(const MoveByʸCMCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_Δy(cp.m_Δy)
    {
    }
    
    MoveByʸCMCommand::~MoveByʸCMCommand()
    {
    }
    
    PostCPtr    MoveByʸCMCommand::clone(rebind_k, const Header& h) const 
    {
        return new MoveByʸCMCommand(*this, h);
    }

    void MoveByʸCMCommand::init_meta()
    {
        auto w = writer<MoveByʸCMCommand>();
        w.description("Position MoveBy Command in Y");
        w.property("Δy", &MoveByʸCMCommand::Δy).tag(kTag_Log).tag(kTag_Save);
        w.alias("MoveByY");
    }
}
