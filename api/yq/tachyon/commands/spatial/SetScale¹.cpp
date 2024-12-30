////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetScale¹.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetScale¹)

namespace yq::tachyon {
    SetScale¹::SetScale¹(TachyonID tid, const Vector1D& v, const Param& p) : 
        SpatialCommand(tid, p), m_scale(v)
    {
    }
    
    SetScale¹::~SetScale¹()
    {
    }
    
    void SetScale¹::init_info()
    {
        auto w = writer<SetScale¹>();
        w.description("Set Scale Command");
        w.property("x", &SetScale¹::x);
    }
}
