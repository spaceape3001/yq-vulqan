////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPosition4M.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>
#include <yq/unit/metatype.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPosition4M)

namespace yq::tachyon {
    SetPosition4M::SetPosition4M(TachyonID tid, const Vector4M& v, const Param& p) : TachyonCommand(tid, p), m_position(v)
    {
    }
    
    SetPosition4M::~SetPosition4M()
    {
    }
    
    void SetPosition4M::init_info()
    {
        auto w = writer<SetPosition4M>();
        w.description("Set Position Command");
        w.property("x", &SetPosition4M::x);
        w.property("y", &SetPosition4M::y);
        w.property("z", &SetPosition4M::z);
        w.property("w", &SetPosition4M::w);
    }
}
