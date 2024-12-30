////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetScale².hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetScale²)

namespace yq::tachyon {
    SetScale²::SetScale²(TachyonID tid, const Vector2D& v, const Param& p) : 
        SpatialCommand(tid, p), m_scale(v)
    {
    }
    
    SetScale²::~SetScale²()
    {
    }
    
    void SetScale²::init_info()
    {
        auto w = writer<SetScale²>();
        w.description("Set Scale Command");
        w.property("x", &SetScale²::x);
        w.property("y", &SetScale²::y);
    }
}
