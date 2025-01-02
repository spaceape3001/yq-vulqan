////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPosition1.hpp"
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPosition¹)

namespace yq::tachyon {
    SetPosition¹::SetPosition¹(TachyonID tid, const Vector1D& v, const Param& p) : 
        SpatialCommand(tid, p), m_position(v)
    {
    }
    
    SetPosition¹::~SetPosition¹()
    {
    }
    
    void SetPosition¹::init_info()
    {
        auto w = writer<SetPosition¹>();
        w.description("Set Position Command");
        w.property("x", &SetPosition¹::x);
    }
}
