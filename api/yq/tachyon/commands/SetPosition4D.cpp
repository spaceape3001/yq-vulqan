////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPosition4D.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPosition4D)

namespace yq::tachyon {
    SetPosition4D::SetPosition4D(TachyonID tid, const Vector4D& v, const Param& p) : TachyonCommand(tid, p), m_position(v)
    {
    }
    
    SetPosition4D::~SetPosition4D()
    {
    }
    
    void SetPosition4D::init_info()
    {
        auto w = writer<SetPosition4D>();
        w.description("Set Position Command");
        w.property("x", &SetPosition4D::x);
        w.property("y", &SetPosition4D::y);
        w.property("z", &SetPosition4D::z);
        w.property("w", &SetPosition4D::w);
    }
}
