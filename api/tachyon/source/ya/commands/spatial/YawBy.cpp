////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/YawBy.hpp>
#include <yt/msg/CommandInfoWriter.hpp>
#include <yq/unit/metatype.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::YawBy)

namespace yq::tachyon {
    YawBy::YawBy(const Header&h, Radian θ) : 
        SpatialCommand(h), m_θ(θ)
    {
    }

    
    YawBy::YawBy(const YawBy&cp, const Header&h) : SpatialCommand(cp, h), m_θ(cp.m_θ)
    {
    }
    
    YawBy::~YawBy()
    {
    }

    PostCPtr    YawBy::clone(rebind_k, const Header&h) const 
    { 
        return new YawBy(*this, h); 
    }
    
    void YawBy::init_info()
    {
        auto w = writer<YawBy>();
        w.description("Yaw By Command");
        w.property("θ", &YawBy::θ);
    }
}
