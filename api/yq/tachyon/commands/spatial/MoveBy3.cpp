////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MoveBy3.hpp"
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveBy³)

namespace yq::tachyon {
    MoveBy³::MoveBy³(TachyonID tid, const Vector3D& Δ, const Param& p) : 
        SpatialCommand(tid, p), m_Δ(Δ)
    {
    }
    
    MoveBy³::~MoveBy³()
    {
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
