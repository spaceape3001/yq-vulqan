////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/scale/SetScaleZ.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetScaleᶻ)

namespace yq::tachyon {
    SetScaleᶻ::SetScaleᶻ(const Header&h, double z) : 
        ScaleCommand(h), m_z(z)
    {
    }
    
    SetScaleᶻ::SetScaleᶻ(const SetScaleᶻ& cp, const Header& h) : 
        ScaleCommand(cp, h), m_z(cp.m_z)
    {
    }

    SetScaleᶻ::~SetScaleᶻ()
    {
    }

    PostCPtr    SetScaleᶻ::clone(rebind_k, const Header&h) const 
    {
        return new SetScaleᶻ(*this, h);
    }
    
    void SetScaleᶻ::init_info()
    {
        auto w = writer<SetScaleᶻ>();
        w.description("Set Scale Command");
        w.property("z", &SetScaleᶻ::z);
    }
}
