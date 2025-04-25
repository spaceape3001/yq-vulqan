////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/position/MoveBy2.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveBy²)

namespace yq::tachyon {
    MoveBy²::MoveBy²(const Header&h) : 
        PositionCommand(h)
    {
    }
    
    MoveBy²::MoveBy²(const Header&h, const Vector2D& Δ) : 
        PositionCommand(h), m_Δ(Δ)
    {
    }

    MoveBy²::MoveBy²(const MoveBy²& cp, const Header&h) : 
        PositionCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    MoveBy²::~MoveBy²()
    {
    }
    
    PostCPtr    MoveBy²::clone(rebind_k, const Header& h) const 
    {
        return new MoveBy²(*this, h);
    }

    void MoveBy²::init_info()
    {
        auto w = writer<MoveBy²>();
        w.description("Position MoveBy Command in 2D");
        w.property("Δx", &MoveBy²::Δx).tag(kTag_Log);
        w.property("Δy", &MoveBy²::Δy).tag(kTag_Log);
        w.property("Δ", &MoveBy²::m_Δ).tag(kTag_Save);
    }
}
