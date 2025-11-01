////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/position/MoveBy2Command.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveBy²Command)

namespace yq::tachyon {
    MoveBy²Command::MoveBy²Command(const Header&h) : 
        PositionCommand(h)
    {
    }
    
    MoveBy²Command::MoveBy²Command(const Header&h, const Vector2D& Δ) : 
        PositionCommand(h), m_Δ(Δ)
    {
    }

    MoveBy²Command::MoveBy²Command(const MoveBy²Command& cp, const Header&h) : 
        PositionCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    MoveBy²Command::~MoveBy²Command()
    {
    }
    
    PostCPtr    MoveBy²Command::clone(rebind_k, const Header& h) const 
    {
        return new MoveBy²Command(*this, h);
    }

    void MoveBy²Command::init_meta()
    {
        auto w = writer<MoveBy²Command>();
        w.description("Position MoveBy Command in 2D");
        w.property("Δx", &MoveBy²Command::Δx).tag(kTag_Log);
        w.property("Δy", &MoveBy²Command::Δy).tag(kTag_Log);
        w.property("Δ", &MoveBy²Command::m_Δ).tag(kTag_Save);
    }
}
