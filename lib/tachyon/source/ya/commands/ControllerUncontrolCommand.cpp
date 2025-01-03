////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/ControllerUncontrolCommand.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ControllerUncontrolCommand)

namespace yq::tachyon {

    ControllerUncontrolCommand::ControllerUncontrolCommand(Controller* v, TachyonID t, const Param& p) : 
        ControllerCommand(v, p), m_tachyon(t)
    {
    }
    
    ControllerUncontrolCommand::ControllerUncontrolCommand(ControllerID v, TachyonID t, const Param& p) : 
        ControllerCommand(v, p), m_tachyon(t)
    {
    }
    
    ControllerUncontrolCommand::~ControllerUncontrolCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ControllerUncontrolCommand::init_info()
    {
        auto w = writer<ControllerUncontrolCommand>();
        w.description("Controller Uncontrol Command");
    }
}
