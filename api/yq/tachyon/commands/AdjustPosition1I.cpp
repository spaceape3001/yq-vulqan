////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AdjustPosition1I.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AdjustPosition1I)

namespace yq::tachyon {
    AdjustPosition1I::AdjustPosition1I(TachyonID tid, const Vector1I& v, const Param& p) : TachyonCommand(tid, p), m_position(v)
    {
    }
    
    AdjustPosition1I::~AdjustPosition1I()
    {
    }
    
    void AdjustPosition1I::init_info()
    {
        auto w = writer<AdjustPosition1I>();
        w.description("Adjust Position Command");
        w.property("x", &AdjustPosition1I::x);
    }
}
