////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/orientation/PitchByCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>
#include <yq/unit/metatype.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::PitchByCommand)

namespace yq::tachyon {
    PitchByCommand::PitchByCommand(const Header&h, Radian θ) : 
        OrientationCommand(h), m_θ(θ)
    {
    }
    
    PitchByCommand::PitchByCommand(const PitchByCommand& cp, const Header&h) : 
        OrientationCommand(cp, h), m_θ(cp.m_θ)
    {
    }

    PitchByCommand::~PitchByCommand()
    {
    }

    PostCPtr    PitchByCommand::clone(rebind_k, const Header&h) const 
    {
        return new PitchByCommand(*this, h);
    }
    
    void PitchByCommand::init_meta()
    {
        auto w = writer<PitchByCommand>();
        w.description("Pitch By Command");
        w.property("θ", &PitchByCommand::θ);
    }
}
