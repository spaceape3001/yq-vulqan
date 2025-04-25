////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/orientation/RollBy.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>
#include <yq/unit/metatype.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::RollBy)

namespace yq::tachyon {
    RollBy::RollBy(const Header&h, Radian θ) : 
        OrientationCommand(h), m_θ(θ)
    {
    }
    
    RollBy::RollBy(const RollBy& cp, const Header&h) : 
        OrientationCommand(cp, h), m_θ(cp.m_θ)
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
