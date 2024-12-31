////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MoveBy3.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveBy3)

namespace yq::tachyon {
    MoveBy3::MoveBy3(TachyonID tid, const Vector3D& Δ, const Param& p) : 
        SpatialCommand(tid, p), m_Δ(Δ)
    {
    }
    
    MoveBy3::~MoveBy3()
    {
    }
    
    void MoveBy3::init_info()
    {
        auto w = writer<MoveBy3>();
        w.description("Position MoveBy Command in 3D");
        w.property("Δx", &MoveBy3::Δx);
        w.property("Δy", &MoveBy3::Δy);
        w.property("Δz", &MoveBy3::Δz);
    }
}
