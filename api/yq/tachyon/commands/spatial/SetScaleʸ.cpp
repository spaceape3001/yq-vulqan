////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetScaleY.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetScaleY)

namespace yq::tachyon {
    SetScaleY::SetScaleY(TachyonID tid, double y, const Param& p) : 
        SpatialCommand(tid, p), m_y(y)
    {
    }
    
    SetScaleY::~SetScaleY()
    {
    }
    
    void SetScaleY::init_info()
    {
        auto w = writer<SetScaleY>();
        w.description("Set Scale Command");
        w.property("y", &SetScaleY::y);
    }
}
