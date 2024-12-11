////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPosition2D.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPosition2D)

namespace yq::tachyon {
    SetPosition2D::SetPosition2D(TachyonID tid, const Vector2D& v, const Param& p) : TachyonCommand(tid, p), m_position(v)
    {
    }
    
    SetPosition2D::~SetPosition2D()
    {
    }
    
    void SetPosition2D::init_info()
    {
        auto w = writer<SetPosition2D>();
        w.description("Set Position Command");
        w.property("x", &SetPosition2D::x);
        w.property("y", &SetPosition2D::y);
    }
}
