////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MoveByˣ.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveByˣ)

namespace yq::tachyon {
    MoveByˣ::MoveByˣ(TachyonID tid, double Δx, const Param& p) : 
        TachyonCommand(tid, p), m_Δx(Δx)
    {
    }
    
    MoveByˣ::~MoveByˣ()
    {
    }
    
    void MoveByˣ::init_info()
    {
        auto w = writer<MoveByˣ>();
        w.description("Position MoveBy Command in ˣ");
        w.property("Δx", &MoveByˣ::Δx);
    }
}
