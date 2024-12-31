////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPositionZ.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPositionZ)

namespace yq::tachyon {
    SetPositionZ::SetPositionZ(TachyonID tid, double z, const Param& p) : 
        SpatialCommand(tid, p), m_z(z)
    {
    }
    
    SetPositionZ::~SetPositionZ()
    {
    }
    
    void SetPositionZ::init_info()
    {
        auto w = writer<SetPositionZ>();
        w.description("Set Position Command");
        w.property("z", &SetPositionZ::z);
    }
}
