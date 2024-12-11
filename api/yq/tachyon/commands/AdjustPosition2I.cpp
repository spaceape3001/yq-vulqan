////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AdjustPosition2I.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AdjustPosition2I)

namespace yq::tachyon {
    AdjustPosition2I::AdjustPosition2I(TachyonID tid, const Vector2I& v, const Param& p) : TachyonCommand(tid, p), m_position(v)
    {
    }
    
    AdjustPosition2I::~AdjustPosition2I()
    {
    }
    
    void AdjustPosition2I::init_info()
    {
        auto w = writer<AdjustPosition2I>();
        w.description("Adjust Position Command");
        w.property("x", &AdjustPosition2I::x);
        w.property("y", &AdjustPosition2I::y);
    }
}
