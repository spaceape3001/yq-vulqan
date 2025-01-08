////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/SetScaleX.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetScaleˣ)

namespace yq::tachyon {
    SetScaleˣ::SetScaleˣ(const Header&h, double x) : 
        SpatialCommand(h), m_x(x)
    {
    }

    SetScaleˣ::SetScaleˣ(const SetScaleˣ& cp, const Header& h) : 
        SpatialCommand(cp, h), m_x(cp.m_x)
    {
    }
    
    SetScaleˣ::~SetScaleˣ()
    {
    }
    
    PostCPtr    SetScaleˣ::clone(rebind_k, const Header&h) const 
    {
        return new SetScaleˣ(*this, h);
    }

    void SetScaleˣ::init_info()
    {
        auto w = writer<SetScaleˣ>();
        w.description("Set Scale Command");
        w.property("x", &SetScaleˣ::x);
    }
}
