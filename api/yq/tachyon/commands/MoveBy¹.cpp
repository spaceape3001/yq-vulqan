////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MoveBy¹.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveBy¹)

namespace yq::tachyon {
    MoveBy¹::MoveBy¹(TachyonID tid, const Vector1D& Δ, const Param& p) : 
        TachyonCommand(tid, p), m_Δ(Δ)
    {
    }
    
    MoveBy¹::~MoveBy¹()
    {
    }
    
    void MoveBy¹::init_info()
    {
        auto w = writer<MoveBy¹>();
        w.description("Position MoveBy Command in ¹D");
        w.property("Δx", &MoveBy¹::Δx);
    }
}
