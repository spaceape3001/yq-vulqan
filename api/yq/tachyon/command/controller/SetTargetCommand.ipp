////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/command/controller/SetTargetCommand.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetTargetCommand)

namespace yq::tachyon {

    SetTargetCommand::SetTargetCommand(const Header& h, TypedID t) : 
        ControllerCommand(h), m_target(t)
    {
    }
    
    SetTargetCommand::SetTargetCommand(const SetTargetCommand& cp, const Header& h) : 
        ControllerCommand(cp, h), m_target(cp.m_target)
    {
    }
    
    SetTargetCommand::~SetTargetCommand()
    {
    }
    
    PostCPtr    SetTargetCommand::clone(rebind_k, const Header& h) const
    {
        return new SetTargetCommand(*this, h);
    }

    ////////////////////////////////////////////////////////////////////////////

    void SetTargetCommand::init_meta()
    {
        auto w = writer<SetTargetCommand>();
        w.description("Set Target Command");
    }
}
