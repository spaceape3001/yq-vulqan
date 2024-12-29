////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPosition³.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPosition³)

namespace yq::tachyon {
    SetPosition³::SetPosition³(TachyonID tid, const Vector3D& v, const Param& p) : TachyonCommand(tid, p), m_position(v)
    {
    }
    
    SetPosition³::~SetPosition³()
    {
    }
    
    void SetPosition³::init_info()
    {
        auto w = writer<SetPosition³>();
        w.description("Set Position Command");
        w.property("x", &SetPosition³::x);
        w.property("y", &SetPosition³::y);
        w.property("z", &SetPosition³::z);
    }
}
