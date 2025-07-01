////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/orientation/SetHeadingCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>
#include <yq/unit/metatype.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetHeadingCommand)

namespace yq::tachyon {
    SetHeadingCommand::SetHeadingCommand(const Header&h) : 
        OrientationCommand(h)
    {
    }

    SetHeadingCommand::SetHeadingCommand(const Header&h, Radian θ) : 
        OrientationCommand(h), m_θ(θ)
    {
    }

    
    SetHeadingCommand::SetHeadingCommand(const SetHeadingCommand&cp, const Header&h) : OrientationCommand(cp, h), m_θ(cp.m_θ)
    {
    }
    
    SetHeadingCommand::~SetHeadingCommand()
    {
    }

    PostCPtr    SetHeadingCommand::clone(rebind_k, const Header&h) const 
    { 
        return new SetHeadingCommand(*this, h); 
    }
    
    void SetHeadingCommand::init_info()
    {
        auto w = writer<SetHeadingCommand>();
        w.description("Set Heading Command");
        w.property("θ", &SetHeadingCommand::m_θ).tag(kTag_Log).tag(kTag_Save);
    }
}
