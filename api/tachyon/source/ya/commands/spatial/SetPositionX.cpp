////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/SetPositionX.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPositionˣ)

namespace yq::tachyon {
    SetPositionˣ::SetPositionˣ(const Header&h, double x) : 
        SpatialCommand(h), m_x(x)
    {
    }
    
    SetPositionˣ::SetPositionˣ(const SetPositionˣ& cp, const Header&h) : 
        SpatialCommand(cp, h), m_x(cp.m_x)
    {
    }

    SetPositionˣ::~SetPositionˣ()
    {
    }

    PostCPtr    SetPositionˣ::clone(rebind_k, const Header& h) const
    {
        return new SetPositionˣ(*this, h);
    }
    
    void SetPositionˣ::init_info()
    {
        auto w = writer<SetPositionˣ>();
        w.description("Set Position Command");
        w.property("x", &SetPositionˣ::x);
    }
}
