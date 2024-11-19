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

    WindowCommand::WindowCommand(Viewer* v, const Param& p) : Command(p), ViewerBind(v)
    {
    }
    
    WindowCommand::WindowCommand(ViewerID v, const Param& p) : Command(p), ViewerBind(v)
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
