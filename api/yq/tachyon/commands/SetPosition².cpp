////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPosition².hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPosition²)

namespace yq::tachyon {
    SetPosition²::SetPosition²(TachyonID tid, const Vector2D& v, const Param& p) : TachyonCommand(tid, p), m_position(v)
    {
    }
    
    SetPosition²::~SetPosition²()
    {
    }
    
    void SetPosition²::init_info()
    {
        auto w = writer<SetPosition²>();
        w.description("Set Position Command");
        w.property("x", &SetPosition²::x);
        w.property("y", &SetPosition²::y);
    }
}
