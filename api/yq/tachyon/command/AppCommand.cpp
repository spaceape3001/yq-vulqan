////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/command/AppCommand.hpp>

#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AppCommand)

namespace yq::tachyon {
    AppCommandMeta::AppCommandMeta(std::string_view zName, CommandMeta& base, const std::source_location& sl) :
        CommandMeta(zName, base, sl)
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

    void AppCommand::init_meta()
    {
        auto w = writer<AppCommand>();
        w.description("App command base class");
    }
}
