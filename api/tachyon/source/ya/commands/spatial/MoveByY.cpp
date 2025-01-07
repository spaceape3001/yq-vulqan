////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/MoveByY.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveByʸ)

namespace yq::tachyon {
    MoveByʸ::MoveByʸ(const Header&h, double Δy) : 
        SpatialCommand(h), m_Δy(Δy)
    {
    }

    MoveByʸ::MoveByʸ(const MoveByʸ& cp, const Header&h) : 
        SpatialCommand(cp, h), m_Δy(cp.m_Δy)
    {
    }
    
    MoveByʸ::~MoveByʸ()
    {
    }
    
    PostCPtr    MoveByʸ::clone(rebind_k, const Header& h) const 
    {
        return new MoveByʸ(*this, h);
    }

    void MoveByʸ::init_info()
    {
        auto w = writer<MoveByʸ>();
        w.description("Position MoveBy Command in Y");
        w.property("Δy", &MoveByʸ::Δy);
    }
}
