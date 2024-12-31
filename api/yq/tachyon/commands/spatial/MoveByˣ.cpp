////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MoveByX.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveByX)

namespace yq::tachyon {
    MoveByX::MoveByX(TachyonID tid, double Δx, const Param& p) : 
        SpatialCommand(tid, p), m_Δx(Δx)
    {
    }
    
    MoveByX::~MoveByX()
    {
    }
    
    void MoveByX::init_info()
    {
        auto w = writer<MoveByX>();
        w.description("Position MoveBy Command in X");
        w.property("Δx", &MoveByX::Δx);
    }
}
