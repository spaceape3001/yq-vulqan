////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MoveByZ.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveByZ)

namespace yq::tachyon {
    MoveByZ::MoveByZ(TachyonID tid, double Δz, const Param& p) : 
        SpatialCommand(tid, p), m_Δz(Δz)
    {
    }
    
    MoveByZ::~MoveByZ()
    {
    }
    
    void MoveByZ::init_info()
    {
        auto w = writer<MoveByZ>();
        w.description("Position MoveBy Command in Z");
        w.property("Δz", &MoveByZ::Δz);
    }
}
