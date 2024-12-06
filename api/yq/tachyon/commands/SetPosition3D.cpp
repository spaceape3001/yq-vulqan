////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPosition3D.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPosition3D)

namespace yq::tachyon {
    SetPosition3D::SetPosition3D(TachyonID tid, const Vector3D& v, const Param& p) : TachyonCommand(tid, p), m_position(v)
    {
    }
    
    SetPosition3D::~SetPosition3D()
    {
    }
    
    void SetPosition3D::init_info()
    {
        auto w = writer<SetPosition3D>();
        w.description("Set Position Command");
        w.property("x", &SetPosition3D::x);
        w.property("y", &SetPosition3D::y);
        w.property("z", &SetPosition3D::z);
    }
}
