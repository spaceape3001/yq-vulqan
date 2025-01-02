////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPositionZ.hpp"
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPositionᶻ)

namespace yq::tachyon {
    SetPositionᶻ::SetPositionᶻ(TachyonID tid, double z, const Param& p) : 
        SpatialCommand(tid, p), m_z(z)
    {
    }
    
    SetPositionᶻ::~SetPositionᶻ()
    {
    }
    
    void SetPositionᶻ::init_info()
    {
        auto w = writer<SetPositionᶻ>();
        w.description("Set Position Command");
        w.property("z", &SetPositionᶻ::z);
    }
}
