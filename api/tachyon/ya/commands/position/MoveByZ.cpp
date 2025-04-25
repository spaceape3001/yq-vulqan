////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/position/MoveByZ.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveByᶻ)

namespace yq::tachyon {
    MoveByᶻ::MoveByᶻ(const Header&h) : 
        PositionCommand(h)
    {
    }
    
    MoveByᶻ::MoveByᶻ(const Header&h, double Δz) : 
        PositionCommand(h), m_Δz(Δz)
    {
    }

    MoveByᶻ::MoveByᶻ(const MoveByᶻ& cp, const Header&h) : 
        PositionCommand(cp, h), m_Δz(cp.m_Δz)
    {
    }

    MoveByᶻ::~MoveByᶻ()
    {
    }
    
    PostCPtr    MoveByᶻ::clone(rebind_k, const Header&h) const 
    {
        return new MoveByᶻ(*this, h);
    }

    void MoveByᶻ::init_info()
    {
        auto w = writer<MoveByᶻ>();
        w.description("Position MoveBy Command in Z");
        w.property("Δz", &MoveByᶻ::Δz).tag(kTag_Log).tag(kTag_Save);
    }
}
