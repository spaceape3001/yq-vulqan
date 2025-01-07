////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/MoveBy3.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveBy³)

namespace yq::tachyon {
    MoveBy³::MoveBy³(const Header&h, const Vector3D& Δ) : 
        SpatialCommand(h), m_Δ(Δ)
    {
    }
    
    MoveBy³::MoveBy³(const MoveBy³&cp, const Header&h) : 
        SpatialCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    MoveBy³::~MoveBy³()
    {
    }

    PostCPtr    MoveBy³::clone(rebind_k, const Header& h) const 
    {
        return new MoveBy³(*this, h);
    }
   
    void MoveBy³::init_info()
    {
        auto w = writer<MoveBy³>();
        w.description("Position MoveBy Command in 3D");
        w.property("Δx", &MoveBy³::Δx);
        w.property("Δy", &MoveBy³::Δy);
        w.property("Δz", &MoveBy³::Δz);
    }
}
