////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/AppCommand.hpp>

#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AppCommand)

namespace yq::tachyon {
    AppCommandInfo::AppCommandInfo(std::string_view zName, CommandInfo& base, const std::source_location& sl) :
        CommandInfo(zName, base, sl)
    {
    }

    ////////////////////////////////////////////////////////////////////////////

    AppCommand::AppCommand(const Header& h) : Command(h)
    {
    }
    
    AppCommand::AppCommand(const AppCommand& cp, const Header& h) : Command(cp, h)
    {
    }
    
    AppCommand::~AppCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void AppCommand::init_info()
    {
        auto w = writer<AppCommand>();
        w.description("App command base class");
    }
}
