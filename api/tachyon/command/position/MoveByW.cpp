////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/position/MoveByW.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveByʷ)

namespace yq::tachyon {
    MoveByʷ::MoveByʷ(const Header&h) : 
        PositionCommand(h)
    {
    }

    MoveByʷ::MoveByʷ(const Header&h, double Δw) : 
        PositionCommand(h), m_Δw(Δw)
    {
    }
    
    MoveByʷ::MoveByʷ(const MoveByʷ& cp, const Header&h) : 
        PositionCommand(cp, h), m_Δw(cp.m_Δw)
    {
    }

    MoveByʷ::~MoveByʷ()
    {
    }
    
    PostCPtr    MoveByʷ::clone(rebind_k, const Header&h) const 
    {
        return new MoveByʷ(*this, h);
    }

    void MoveByʷ::init_info()
    {
        auto w = writer<MoveByʷ>();
        w.description("Position MoveBy Command in X");
        w.property("Δw", &MoveByʷ::Δw).tag(kTag_Log).tag(kTag_Save);
    }
}
