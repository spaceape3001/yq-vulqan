////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ControllerCommand.hpp"

#include <yq/post/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ControllerCommand)

namespace yq::tachyon {
    ControllerCommandInfo::ControllerCommandInfo(std::string_view zName, post::CommandInfo& base, const std::source_location& sl) :
        post::CommandInfo(zName, base, sl)
    {
    }

    ////////////////////////////////////////////////////////////////////////////

    ControllerCommand::ControllerCommand(Controller* v, const Param& p) : post::Command(p), ControllerBind(v)
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
