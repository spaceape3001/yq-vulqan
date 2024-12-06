////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPosition2I.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPosition2I)

namespace yq::tachyon {
    SetPosition2I::SetPosition2I(TachyonID tid, const Vector2I& v, const Param& p) : TachyonCommand(tid, p), m_position(v)
    {
    }
    
    SetPosition2I::~SetPosition2I()
    {
    }
    
    void SetPosition2I::init_info()
    {
        auto w = writer<SetPosition2I>();
        w.description("Set Position Command");
        w.property("x", &SetPosition2I::x);
        w.property("y", &SetPosition2I::y);
    }
}
