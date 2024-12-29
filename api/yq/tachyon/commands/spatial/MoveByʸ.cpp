////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MoveByʸ.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveByʸ)

namespace yq::tachyon {
    MoveByʸ::MoveByʸ(TachyonID tid, double Δy, const Param& p) : 
        SpatialCommand(tid, p), m_Δy(Δy)
    {
    }
    
    MoveByʸ::~MoveByʸ()
    {
    }
    
    void MoveByʸ::init_info()
    {
        auto w = writer<MoveByʸ>();
        w.description("Position MoveBy Command in ʸ");
        w.property("Δy", &MoveByʸ::Δy);
    }
}
