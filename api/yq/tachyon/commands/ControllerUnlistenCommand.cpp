////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ControllerUnlistenCommand.hpp"
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ControllerUnlistenCommand)

namespace yq::tachyon {

    ControllerUnlistenCommand::ControllerUnlistenCommand(Controller* v, TachyonID t, const Param& p) : 
        ControllerCommand(v, p), m_tachyon(t)
    {
    }
    
    ControllerUnlistenCommand::ControllerUnlistenCommand(ControllerID v, TachyonID t, const Param& p) : 
        ControllerCommand(v, p), m_tachyon(t)
    {
    }
    
    ControllerUnlistenCommand::~ControllerUnlistenCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ControllerUnlistenCommand::init_info()
    {
        auto w = writer<ControllerUnlistenCommand>();
        w.description("Controller Unlisten Command");
    }
}
