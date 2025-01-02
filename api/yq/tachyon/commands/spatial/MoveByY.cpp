////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MoveByY.hpp"
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveByY)

namespace yq::tachyon {
    MoveByY::MoveByY(TachyonID tid, double Δy, const Param& p) : 
        SpatialCommand(tid, p), m_Δy(Δy)
    {
    }
    
    MoveByY::~MoveByY()
    {
    }
    
    void MoveByY::init_info()
    {
        auto w = writer<MoveByY>();
        w.description("Position MoveBy Command in Y");
        w.property("Δy", &MoveByY::Δy);
    }
}
