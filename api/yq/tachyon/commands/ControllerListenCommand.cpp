////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ControllerListenCommand.hpp"
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ControllerListenCommand)

namespace yq::tachyon {

    ControllerListenCommand::ControllerListenCommand(Controller* v, TachyonID t, const Param& p) : 
        ControllerCommand(v, p), m_tachyon(t)
    {
    }
    
    ControllerListenCommand::ControllerListenCommand(ControllerID v, TachyonID t, const Param& p) : 
        ControllerCommand(v, p), m_tachyon(t)
    {
    }
    
    ControllerListenCommand::~ControllerListenCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ControllerListenCommand::init_info()
    {
        auto w = writer<ControllerListenCommand>();
        w.description("Controller Listen Command");
    }
}
