////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/orientation/PitchBy.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>
#include <yq/unit/metatype.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::PitchBy)

namespace yq::tachyon {
    PitchBy::PitchBy(const Header&h, Radian θ) : 
        OrientationCommand(h), m_θ(θ)
    {
    }
    
    PitchBy::PitchBy(const PitchBy& cp, const Header&h) : 
        OrientationCommand(cp, h), m_θ(cp.m_θ)
    {
    }

    PitchBy::~PitchBy()
    {
    }

    PostCPtr    PitchBy::clone(rebind_k, const Header&h) const 
    {
        return new PitchBy(*this, h);
    }
    
    void PitchBy::init_info()
    {
        auto w = writer<PitchBy>();
        w.description("Pitch By Command");
        w.property("θ", &PitchBy::θ);
    }
}
