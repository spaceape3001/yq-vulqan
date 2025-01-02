////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MoveByZ.hpp"
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveByᶻ)

namespace yq::tachyon {
    MoveByᶻ::MoveByᶻ(TachyonID tid, double Δz, const Param& p) : 
        SpatialCommand(tid, p), m_Δz(Δz)
    {
    }
    
    MoveByᶻ::~MoveByᶻ()
    {
    }
    
    void MoveByᶻ::init_info()
    {
        auto w = writer<MoveByᶻ>();
        w.description("Position MoveBy Command in Z");
        w.property("Δz", &MoveByᶻ::Δz);
    }
}
