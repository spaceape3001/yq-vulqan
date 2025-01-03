////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/WindowTitleCommand.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowTitleCommand)

namespace yq::tachyon {

    WindowTitleCommand::WindowTitleCommand(Window* v, std::string_view szTitle, const Param& p) : WindowCommand(v, p), m_title(szTitle)
    {
    }
    
    WindowTitleCommand::WindowTitleCommand(WindowID v, std::string_view szTitle, const Param& p) : WindowCommand(v, p), m_title(szTitle)
    {
    }

    WindowTitleCommand::~WindowTitleCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WindowTitleCommand::init_info()
    {
        auto w = writer<WindowTitleCommand>();
        w.description("Window Title Command");
        w.property("title", &WindowTitleCommand::title).description("Window Title");
    }
}
