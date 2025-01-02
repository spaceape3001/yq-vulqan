////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetSize2.hpp"
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetSize²)

namespace yq::tachyon {
    SetSize²::SetSize²(TachyonID tid, const Size2D& v, const Param& p) : TachyonCommand(tid, p), m_size(v)
    {
    }
    
    SetSize²::~SetSize²()
    {
    }
    
    void SetSize²::init_info()
    {
        auto w = writer<SetSize²>();
        w.description("Set Size Command in 2D");
        w.property("x", &SetSize²::x);
        w.property("y", &SetSize²::y);
    }
}
