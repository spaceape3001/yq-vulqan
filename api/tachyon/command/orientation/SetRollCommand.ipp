////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/orientation/SetRollCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>
#include <yq/unit/metatype.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetRollCommand)

namespace yq::tachyon {
    SetRollCommand::SetRollCommand(const Header& h) : OrientationCommand(h)
    {
    }

    SetRollCommand::SetRollCommand(const Header&h, Radian θ) : 
        OrientationCommand(h), m_θ(θ)
    {
    }
    
    SetRollCommand::SetRollCommand(const SetRollCommand& cp, const Header&h) : 
        OrientationCommand(cp, h), m_θ(cp.m_θ)
    {
    }

    SetRollCommand::~SetRollCommand()
    {
    }

    PostCPtr    SetRollCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetRollCommand(*this, h);
    }
    
    void SetRollCommand::init_meta()
    {
        auto w = writer<SetRollCommand>();
        w.description("Set Roll Command");
        w.property("θ", &SetRollCommand::m_θ).tag(kTag_Log).tag(kTag_Save);
    }
}
