////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPosition3I.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPosition3I)

namespace yq::tachyon {
    SetPosition3I::SetPosition3I(TachyonID tid, const Vector3I& v, const Param& p) : TachyonCommand(tid, p), m_position(v)
    {
    }
    
    SetPosition3I::~SetPosition3I()
    {
    }
    
    void SetPosition3I::init_info()
    {
        auto w = writer<SetPosition3I>();
        w.description("Set Position Command");
        w.property("x", &SetPosition3I::x);
        w.property("y", &SetPosition3I::y);
        w.property("z", &SetPosition3I::z);
    }
}
