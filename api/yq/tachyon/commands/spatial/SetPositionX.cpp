////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPositionX.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPositionˣ)

namespace yq::tachyon {
    SetPositionˣ::SetPositionˣ(TachyonID tid, double x, const Param& p) : 
        SpatialCommand(tid, p), m_x(x)
    {
    }
    
    SetPositionˣ::~SetPositionˣ()
    {
    }
    
    void SetPositionˣ::init_info()
    {
        auto w = writer<SetPositionˣ>();
        w.description("Set Position Command");
        w.property("x", &SetPositionˣ::x);
    }
}
