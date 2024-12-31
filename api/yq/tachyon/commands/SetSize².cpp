////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetSize2.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetSize2)

namespace yq::tachyon {
    SetSize2::SetSize2(TachyonID tid, const Size2D& v, const Param& p) : TachyonCommand(tid, p), m_size(v)
    {
    }
    
    SetSize2::~SetSize2()
    {
    }
    
    void SetSize2::init_info()
    {
        auto w = writer<SetSize2>();
        w.description("Set Size Command in 2D");
        w.property("x", &SetSize2::x);
        w.property("y", &SetSize2::y);
    }
}
