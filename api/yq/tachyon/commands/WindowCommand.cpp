////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowCommand.hpp"

#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowCommand)

namespace yq::tachyon {
    WindowCommandInfo::WindowCommandInfo(std::string_view zName, CommandInfo& base, const std::source_location& sl) :
        CommandInfo(zName, base, sl)
    {
    }

    ////////////////////////////////////////////////////////////////////////////

    WindowCommand::WindowCommand(const Window* v, const Param& p) : Command(p), WindowBind(v)
    {
    }
    
    WindowCommand::WindowCommand(WindowID v, const Param& p) : Command(p), WindowBind(v)
    {
    }

    WindowCommand::~WindowCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WindowCommand::init_info()
    {
        auto w = writer<WindowCommand>();
        w.description("Window command base class");
    }
}
