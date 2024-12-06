////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AdjustPosition4I.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AdjustPosition4I)

namespace yq::tachyon {
    AdjustPosition4I::AdjustPosition4I(TachyonID tid, const Vector4I& v, const Param& p) : TachyonCommand(tid, p), m_position(v)
    {
    }
    
    AdjustPosition4I::~AdjustPosition4I()
    {
    }
    
    void AdjustPosition4I::init_info()
    {
        auto w = writer<AdjustPosition4I>();
        w.description("Adjust Position Command");
        w.property("x", &AdjustPosition4I::x);
        w.property("y", &AdjustPosition4I::y);
        w.property("z", &AdjustPosition4I::z);
        w.property("w", &AdjustPosition4I::w);
    }
}
