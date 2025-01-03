////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/ControllerDisableCommand.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ControllerDisableCommand)

namespace yq::tachyon {

    ControllerDisableCommand::ControllerDisableCommand(Controller* v, const Param& p) : ControllerCommand(v, p)
    {
    }
    
    ControllerDisableCommand::ControllerDisableCommand(ControllerID v, const Param& p) : ControllerCommand(v, p)
    {
    }
    
    ControllerDisableCommand::~ControllerDisableCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ControllerDisableCommand::init_info()
    {
        auto w = writer<ControllerDisableCommand>();
        w.description("Controller Disable Command");
    }
}