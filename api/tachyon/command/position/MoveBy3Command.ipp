////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/position/MoveBy3Command.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveBy³Command)

namespace yq::tachyon {
    MoveBy³Command::MoveBy³Command(const Header&h) : 
        PositionCommand(h)
    {
    }

    MoveBy³Command::MoveBy³Command(const Header&h, const Vector3D& Δ) : 
        PositionCommand(h), m_Δ(Δ)
    {
    }
    
    MoveBy³Command::MoveBy³Command(const MoveBy³Command&cp, const Header&h) : 
        PositionCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    MoveBy³Command::~MoveBy³Command()
    {
    }

    PostCPtr    MoveBy³Command::clone(rebind_k, const Header& h) const 
    {
        return new MoveBy³Command(*this, h);
    }
   
    void MoveBy³Command::init_info()
    {
        auto w = writer<MoveBy³Command>();
        w.description("Position MoveBy Command in 3D");
        w.property("Δx", &MoveBy³Command::Δx).tag(kTag_Log);
        w.property("Δy", &MoveBy³Command::Δy).tag(kTag_Log);
        w.property("Δz", &MoveBy³Command::Δz).tag(kTag_Log);
        w.property("Δ", &MoveBy³Command::m_Δ).tag(kTag_Save);
    }
}
