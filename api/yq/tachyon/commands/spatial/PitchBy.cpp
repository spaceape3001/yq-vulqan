////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PitchBy.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>
#include <yq/unit/metatype.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::PitchBy)

namespace yq::tachyon {
    PitchBy::PitchBy(TachyonID tid, Radian θ, const Param& p) : 
        SpatialCommand(tid, p), m_θ(θ)
    {
    }
    
    PitchBy::~PitchBy()
    {
    }
    
    void PitchBy::init_info()
    {
        auto w = writer<PitchBy>();
        w.description("Pitch By Command");
        w.property("θ", &PitchBy::θ);
    }
}
