////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPosition4I.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPosition4I)

namespace yq::tachyon {
    SetPosition4I::SetPosition4I(TachyonID tid, const Vector4I& v, const Param& p) : TachyonCommand(tid, p), m_position(v)
    {
    }
    
    SetPosition4I::~SetPosition4I()
    {
    }
    
    void SetPosition4I::init_info()
    {
        auto w = writer<SetPosition4I>();
        w.description("Set Position Command");
        w.property("x", &SetPosition4I::x);
        w.property("y", &SetPosition4I::y);
        w.property("z", &SetPosition4I::z);
        w.property("w", &SetPosition4I::w);
    }
}
