////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/orientation/SetPitchCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>
#include <yq/unit/metatype.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPitchCommand)

namespace yq::tachyon {
    SetPitchCommand::SetPitchCommand(const Header&h) : 
        OrientationCommand(h)
    {
    }
    
    SetPitchCommand::SetPitchCommand(const Header&h, Radian θ) : 
        OrientationCommand(h), m_θ(θ)
    {
    }

    SetPitchCommand::SetPitchCommand(const SetPitchCommand& cp, const Header&h) : 
        OrientationCommand(cp, h), m_θ(cp.m_θ)
    {
    }

    SetPitchCommand::~SetPitchCommand()
    {
    }

    PostCPtr    SetPitchCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetPitchCommand(*this, h);
    }
    
    void SetPitchCommand::init_info()
    {
        auto w = writer<SetPitchCommand>();
        w.description("Set Pitch Command");
        w.property("θ", &SetPitchCommand::m_θ).tag(kTag_Log).tag(kTag_Save);
    }
}
