////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPosition3M.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>
#include <yq/unit/metatype.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPosition3M)

namespace yq::tachyon {
    SetPosition3M::SetPosition3M(TachyonID tid, const Vector3M& v, const Param& p) : TachyonCommand(tid, p), m_position(v)
    {
    }
    
    SetPosition3M::~SetPosition3M()
    {
    }
    
    void SetPosition3M::init_info()
    {
        auto w = writer<SetPosition3M>();
        w.description("Set Position Command");
        w.property("x", &SetPosition3M::x);
        w.property("y", &SetPosition3M::y);
        w.property("z", &SetPosition3M::z);
    }
}
