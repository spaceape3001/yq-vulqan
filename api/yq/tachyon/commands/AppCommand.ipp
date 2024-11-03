////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AppCommand.hpp"

#include <yq/post/CommandInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AppCommand)

namespace yq::tachyon {
    AppCommandInfo::AppCommandInfo(std::string_view zName, post::CommandInfo& base, const std::source_location& sl) :
        post::CommandInfo(zName, base, sl)
    {
    }

    ////////////////////////////////////////////////////////////////////////////

    AppCommand::AppCommand(const Param& p) : post::Command(p)
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
    
    YQ_INVOKE(AppCommand::init_info();)
}
