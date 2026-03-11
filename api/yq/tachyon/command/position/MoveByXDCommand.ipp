////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MoveByXDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveByˣDCommand)

namespace yq::tachyon {
    MoveByˣDCommand::MoveByˣDCommand(const Header&h) : 
        PositionCommand(h)
    {
    }

    MoveByˣDCommand::MoveByˣDCommand(const Header&h, double Δx) : 
        PositionCommand(h), m_Δx(Δx)
    {
    }
    
    MoveByˣDCommand::MoveByˣDCommand(const MoveByˣDCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_Δx(cp.m_Δx)
    {
    }

    MoveByˣDCommand::~MoveByˣDCommand()
    {
    }
    
    PostCPtr    MoveByˣDCommand::clone(rebind_k, const Header&h) const 
    {
        return new MoveByˣDCommand(*this, h);
    }

    void MoveByˣDCommand::init_meta()
    {
        auto w = writer<MoveByˣDCommand>();
        w.description("Position MoveBy Command in X");
        w.property("Δx", &MoveByˣDCommand::Δx).tag(kTag_Log).tag(kTag_Save);
        w.alias("MoveByX");
    }
}
