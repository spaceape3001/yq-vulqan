////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPosition2M.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>
#include <yq/unit/metatype.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPosition2M)

namespace yq::tachyon {
    SetPosition2M::SetPosition2M(TachyonID tid, const Vector2M& v, const Param& p) : TachyonCommand(tid, p), m_position(v)
    {
    }
    
    SetPosition2M::~SetPosition2M()
    {
    }
    
    void SetPosition2M::init_info()
    {
        auto w = writer<SetPosition2M>();
        w.description("Set Position Command");
        w.property("x", &SetPosition2M::x);
        w.property("y", &SetPosition2M::y);
    }
}
