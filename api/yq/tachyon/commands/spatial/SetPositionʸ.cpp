////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPositionY.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPositionY)

namespace yq::tachyon {
    SetPositionY::SetPositionY(TachyonID tid, double y, const Param& p) : 
        SpatialCommand(tid, p), m_y(y)
    {
    }
    
    SetPositionY::~SetPositionY()
    {
    }
    
    void SetPositionY::init_info()
    {
        auto w = writer<SetPositionY>();
        w.description("Set Position Command");
        w.property("y", &SetPositionY::y);
    }
}
