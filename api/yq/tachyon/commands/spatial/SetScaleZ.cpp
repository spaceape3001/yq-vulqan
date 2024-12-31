////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetScaleZ.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetScaleZ)

namespace yq::tachyon {
    SetScaleZ::SetScaleZ(TachyonID tid, double z, const Param& p) : 
        SpatialCommand(tid, p), m_z(z)
    {
    }
    
    SetScaleZ::~SetScaleZ()
    {
    }
    
    void SetScaleZ::init_info()
    {
        auto w = writer<SetScaleZ>();
        w.description("Set Scale Command");
        w.property("z", &SetScaleZ::z);
    }
}
