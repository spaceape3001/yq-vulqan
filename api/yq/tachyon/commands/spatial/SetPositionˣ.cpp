////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPositionX.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPositionX)

namespace yq::tachyon {
    SetPositionX::SetPositionX(TachyonID tid, double x, const Param& p) : 
        SpatialCommand(tid, p), m_x(x)
    {
    }
    
    SetPositionX::~SetPositionX()
    {
    }
    
    void SetPositionX::init_info()
    {
        auto w = writer<SetPositionX>();
        w.description("Set Position Command");
        w.property("x", &SetPositionX::x);
    }
}
