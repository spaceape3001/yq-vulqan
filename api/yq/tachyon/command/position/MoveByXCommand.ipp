////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/command/position/MoveByXCommand.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveByˣCommand)

namespace yq::tachyon {
    MoveByˣCommand::MoveByˣCommand(const Header&h) : 
        PositionCommand(h)
    {
    }

    MoveByˣCommand::MoveByˣCommand(const Header&h, double Δx) : 
        PositionCommand(h), m_Δx(Δx)
    {
    }
    
    MoveByˣCommand::MoveByˣCommand(const MoveByˣCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_Δx(cp.m_Δx)
    {
    }

    MoveByˣCommand::~MoveByˣCommand()
    {
    }
    
    PostCPtr    MoveByˣCommand::clone(rebind_k, const Header&h) const 
    {
        return new MoveByˣCommand(*this, h);
    }

    void MoveByˣCommand::init_meta()
    {
        auto w = writer<MoveByˣCommand>();
        w.description("Position MoveBy Command in X");
        w.property("Δx", &MoveByˣCommand::Δx).tag(kTag_Log).tag(kTag_Save);
    }
}
