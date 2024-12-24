////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ControllerCommand.hpp"

#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ControllerCommand)

namespace yq::tachyon {
    ControllerCommandInfo::ControllerCommandInfo(std::string_view zName, CommandInfo& base, const std::source_location& sl) :
        CommandInfo(zName, base, sl)
    {
    }

    ////////////////////////////////////////////////////////////////////////////

    ControllerCommand::ControllerCommand(Controller* v, const Param& p) : Command(p), ControllerBind(v)
    {
    }
    
    ControllerCommand::ControllerCommand(ControllerID v, const Param& p) : Command(p), ControllerBind(v)
    {
    }

    ControllerCommand::~ControllerCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ControllerCommand::init_info()
    {
        auto w = writer<ControllerCommand>();
        w.description("Controller command base class");
    }
}
