////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetScaleZ.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetScaleᶻ)

namespace yq::tachyon {
    SetScaleᶻ::SetScaleᶻ(TachyonID tid, double z, const Param& p) : 
        SpatialCommand(tid, p), m_z(z)
    {
    }
    
    SetScaleᶻ::~SetScaleᶻ()
    {
    }
    
    void SetScaleᶻ::init_info()
    {
        auto w = writer<SetScaleᶻ>();
        w.description("Set Scale Command");
        w.property("z", &SetScaleᶻ::z);
    }
}
