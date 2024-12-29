////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MoveByᶻ.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveByᶻ)

namespace yq::tachyon {
    MoveByᶻ::MoveByᶻ(TachyonID tid, double Δz, const Param& p) : 
        TachyonCommand(tid, p), m_Δz(Δz)
    {
    }
    
    MoveByᶻ::~MoveByᶻ()
    {
    }
    
    void MoveByᶻ::init_info()
    {
        auto w = writer<MoveByᶻ>();
        w.description("Position MoveBy Command in ᶻ");
        w.property("Δz", &MoveByᶻ::Δz);
    }
}
