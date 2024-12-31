////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetScaleX.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetScaleˣ)

namespace yq::tachyon {
    SetScaleˣ::SetScaleˣ(TachyonID tid, double x, const Param& p) : 
        SpatialCommand(tid, p), m_x(x)
    {
    }
    
    SetScaleˣ::~SetScaleˣ()
    {
    }
    
    void SetScaleˣ::init_info()
    {
        auto w = writer<SetScaleˣ>();
        w.description("Set Scale Command");
        w.property("x", &SetScaleˣ::x);
    }
}
