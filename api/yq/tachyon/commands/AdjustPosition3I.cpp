////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AdjustPosition3I.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AdjustPosition3I)

namespace yq::tachyon {
    AdjustPosition3I::AdjustPosition3I(TachyonID tid, const Vector3I& v, const Param& p) : TachyonCommand(tid, p), m_position(v)
    {
    }
    
    AdjustPosition3I::~AdjustPosition3I()
    {
    }
    
    void AdjustPosition3I::init_info()
    {
        auto w = writer<AdjustPosition3I>();
        w.description("Adjust Position Command");
        w.property("x", &AdjustPosition3I::x);
        w.property("y", &AdjustPosition3I::y);
        w.property("z", &AdjustPosition3I::z);
    }
}
