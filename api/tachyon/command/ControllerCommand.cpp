////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/ControllerCommand.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ControllerCommand)

namespace yq::tachyon {
    ControllerCommand::ControllerCommand(const Header& h) : Command(h)
    {
    }
    
    ControllerCommand::ControllerCommand(const ControllerCommand& cp, const Header& h) : Command(cp, h)
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
