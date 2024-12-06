////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPosition1M.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>
#include <yq/unit/metatype.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPosition1M)

namespace yq::tachyon {
    SetPosition1M::SetPosition1M(TachyonID tid, const Vector1M& v, const Param& p) : TachyonCommand(tid, p), m_position(v)
    {
    }
    
    SetPosition1M::~SetPosition1M()
    {
    }
    
    void SetPosition1M::init_info()
    {
        auto w = writer<SetPosition1M>();
        w.description("Set Position Command");
        w.property("x", &SetPosition1M::x);
    }
}
