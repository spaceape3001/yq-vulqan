////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MoveBy1.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveBy1)

namespace yq::tachyon {
    MoveBy1::MoveBy1(TachyonID tid, const Vector1D& Δ, const Param& p) : 
        SpatialCommand(tid, p), m_Δ(Δ)
    {
    }
    
    MoveBy1::~MoveBy1()
    {
    }
    
    void MoveBy1::init_info()
    {
        auto w = writer<MoveBy1>();
        w.description("Position MoveBy Command in 1D");
        w.property("Δx", &MoveBy1::Δx);
    }
}
