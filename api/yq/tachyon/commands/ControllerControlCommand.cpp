////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ControllerControlCommand.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ControllerControlCommand)

namespace yq::tachyon {

    ControllerControlCommand::ControllerControlCommand(Controller* v, TachyonID t, const Param& p) : 
        ControllerCommand(v, p), m_tachyon(t)
    {
    }
    
    ControllerControlCommand::ControllerControlCommand(ControllerID v, TachyonID t, const Param& p) : 
        ControllerCommand(v, p), m_tachyon(t)
    {
    }
    
    ControllerControlCommand::~ControllerControlCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ControllerControlCommand::init_info()
    {
        auto w = writer<ControllerControlCommand>();
        w.description("Controller Control Command");
    }
}
