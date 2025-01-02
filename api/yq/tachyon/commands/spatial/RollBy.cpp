////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "RollBy.hpp"
#include <yt/msg/CommandInfoWriter.hpp>
#include <yq/unit/metatype.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::RollBy)

namespace yq::tachyon {
    RollBy::RollBy(TachyonID tid, Radian θ, const Param& p) : 
        SpatialCommand(tid, p), m_θ(θ)
    {
    }
    
    RollBy::~RollBy()
    {
    }
    
    void RollBy::init_info()
    {
        auto w = writer<RollBy>();
        w.description("Roll By Command");
        w.property("θ", &RollBy::θ);
    }
}
