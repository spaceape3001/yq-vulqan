////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPosition1I.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPosition1I)

namespace yq::tachyon {
    SetPosition1I::SetPosition1I(TachyonID tid, const Vector1I& v, const Param& p) : TachyonCommand(tid, p), m_position(v)
    {
    }
    
    SetPosition1I::~SetPosition1I()
    {
    }
    
    void SetPosition1I::init_info()
    {
        auto w = writer<SetPosition1I>();
        w.description("Set Position Command");
        w.property("x", &SetPosition1I::x);
    }
}
