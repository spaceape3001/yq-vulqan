////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/ControllerEnableCommand.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ControllerEnableCommand)

namespace yq::tachyon {

    ControllerEnableCommand::ControllerEnableCommand(Controller* v, const Param& p) : ControllerCommand(v, p)
    {
    }
    
    ControllerEnableCommand::ControllerEnableCommand(ControllerID v, const Param& p) : ControllerCommand(v, p)
    {
    }
    
    ControllerEnableCommand::~ControllerEnableCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ControllerEnableCommand::init_info()
    {
        auto w = writer<ControllerEnableCommand>();
        w.description("Controller Enable Command");
    }
}
