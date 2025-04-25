////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/position/SetPositionZ.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPositionᶻ)

namespace yq::tachyon {
    SetPositionᶻ::SetPositionᶻ(const Header&h, double z) : 
        PositionCommand(h), m_z(z)
    {
    }

    SetPositionᶻ::SetPositionᶻ(const SetPositionᶻ& cp, const Header&h) : 
        PositionCommand(cp, h), m_z(cp.m_z)
    {
    }
    
    SetPositionᶻ::~SetPositionᶻ()
    {
    }
    
    PostCPtr    SetPositionᶻ::clone(rebind_k, const Header&h) const 
    {
        return new SetPositionᶻ(*this, h);
    }

    void SetPositionᶻ::init_info()
    {
        auto w = writer<SetPositionᶻ>();
        w.description("Set Position Command");
        w.property("z", &SetPositionᶻ::z);
    }
}
