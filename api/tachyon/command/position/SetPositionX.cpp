////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/position/SetPositionX.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPositionˣ)

namespace yq::tachyon {
    SetPositionˣ::SetPositionˣ(const Header&h, double x) : 
        PositionCommand(h), m_x(x)
    {
    }
    
    SetPositionˣ::SetPositionˣ(const SetPositionˣ& cp, const Header&h) : 
        PositionCommand(cp, h), m_x(cp.m_x)
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
