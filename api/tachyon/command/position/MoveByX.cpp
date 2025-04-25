////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/position/MoveByX.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveByˣ)

namespace yq::tachyon {
    MoveByˣ::MoveByˣ(const Header&h) : 
        PositionCommand(h)
    {
    }

    MoveByˣ::MoveByˣ(const Header&h, double Δx) : 
        PositionCommand(h), m_Δx(Δx)
    {
    }
    
    MoveByˣ::MoveByˣ(const MoveByˣ& cp, const Header&h) : 
        PositionCommand(cp, h), m_Δx(cp.m_Δx)
    {
    }

    MoveByˣ::~MoveByˣ()
    {
    }
    
    PostCPtr    MoveByˣ::clone(rebind_k, const Header&h) const 
    {
        return new MoveByˣ(*this, h);
    }

    void MoveByˣ::init_info()
    {
        auto w = writer<MoveByˣ>();
        w.description("Position MoveBy Command in X");
        w.property("Δx", &MoveByˣ::Δx).tag(kTag_Log).tag(kTag_Save);
    }
}
