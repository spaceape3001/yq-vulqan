////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetSize2I.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetSize2I)

namespace yq::tachyon {
    SetSize2I::SetSize2I(TachyonID tid, const Size2I& v, const Param& p) : TachyonCommand(tid, p), m_size(v)
    {
    }
    
    SetSize2I::~SetSize2I()
    {
    }
    
    void SetSize2I::init_info()
    {
        auto w = writer<SetSize2I>();
        w.description("Set Size Command");
        w.property("x", &SetSize2I::x);
        w.property("y", &SetSize2I::y);
    }
}
