////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/RollBy.hpp>
#include <yt/msg/CommandInfoWriter.hpp>
#include <yq/unit/metatype.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::RollBy)

namespace yq::tachyon {
    RollBy::RollBy(const Header&h, Radian θ) : 
        SpatialCommand(h), m_θ(θ)
    {
    }
    
    RollBy::RollBy(const RollBy& cp, const Header&h) : 
        SpatialCommand(cp, h), m_θ(cp.m_θ)
    {
    }

    RollBy::~RollBy()
    {
    }

    PostCPtr    RollBy::clone(rebind_k, const Header&h) const 
    {
        return new RollBy(*this, h);
    }
    
    void RollBy::init_info()
    {
        auto w = writer<RollBy>();
        w.description("Roll By Command");
        w.property("θ", &RollBy::θ);
    }
}
