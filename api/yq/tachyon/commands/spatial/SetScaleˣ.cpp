////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetScaleX.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetScaleX)

namespace yq::tachyon {
    SetScaleX::SetScaleX(TachyonID tid, double x, const Param& p) : 
        SpatialCommand(tid, p), m_x(x)
    {
    }
    
    SetScaleX::~SetScaleX()
    {
    }
    
    void SetScaleX::init_info()
    {
        auto w = writer<SetScaleX>();
        w.description("Set Scale Command");
        w.property("x", &SetScaleX::x);
    }
}
