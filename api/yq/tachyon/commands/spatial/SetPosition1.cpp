////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPosition1.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPosition1)

namespace yq::tachyon {
    SetPosition1::SetPosition1(TachyonID tid, const Vector1D& v, const Param& p) : 
        SpatialCommand(tid, p), m_position(v)
    {
    }
    
    SetPosition1::~SetPosition1()
    {
    }
    
    void SetPosition1::init_info()
    {
        auto w = writer<SetPosition1>();
        w.description("Set Position Command");
        w.property("x", &SetPosition1::x);
    }
}
