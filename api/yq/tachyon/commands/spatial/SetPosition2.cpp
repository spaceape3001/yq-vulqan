////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPosition2.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPosition2)

namespace yq::tachyon {
    SetPosition2::SetPosition2(TachyonID tid, const Vector2D& v, const Param& p) : 
        SpatialCommand(tid, p), m_position(v)
    {
    }
    
    SetPosition2::~SetPosition2()
    {
    }
    
    void SetPosition2::init_info()
    {
        auto w = writer<SetPosition2>();
        w.description("Set Position Command");
        w.property("x", &SetPosition2::x);
        w.property("y", &SetPosition2::y);
    }
}
