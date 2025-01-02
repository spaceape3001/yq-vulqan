////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetScale1.hpp"
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetScale1)

namespace yq::tachyon {
    SetScale1::SetScale1(TachyonID tid, const Vector1D& v, const Param& p) : 
        SpatialCommand(tid, p), m_scale(v)
    {
    }
    
    SetScale1::~SetScale1()
    {
    }
    
    void SetScale1::init_info()
    {
        auto w = writer<SetScale1>();
        w.description("Set Scale Command");
        w.property("x", &SetScale1::x);
    }
}
