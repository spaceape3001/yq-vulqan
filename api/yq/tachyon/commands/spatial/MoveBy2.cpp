////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MoveBy2.hpp"
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveBy²)

namespace yq::tachyon {
    MoveBy²::MoveBy²(TachyonID tid, const Vector2D& Δ, const Param& p) : 
        SpatialCommand(tid, p), m_Δ(Δ)
    {
    }
    
    MoveBy²::~MoveBy²()
    {
    }
    
    void MoveBy²::init_info()
    {
        auto w = writer<MoveBy²>();
        w.description("Position MoveBy Command in 2D");
        w.property("Δx", &MoveBy²::Δx);
        w.property("Δy", &MoveBy²::Δy);
    }
}
