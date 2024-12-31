////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MoveBy2.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveBy2)

namespace yq::tachyon {
    MoveBy2::MoveBy2(TachyonID tid, const Vector2D& Δ, const Param& p) : 
        SpatialCommand(tid, p), m_Δ(Δ)
    {
    }
    
    MoveBy2::~MoveBy2()
    {
    }
    
    void MoveBy2::init_info()
    {
        auto w = writer<MoveBy2>();
        w.description("Position MoveBy Command in 2D");
        w.property("Δx", &MoveBy2::Δx);
        w.property("Δy", &MoveBy2::Δy);
    }
}
