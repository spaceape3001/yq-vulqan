////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/WindowShowCommand.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowShowCommand)

namespace yq::tachyon {

    WindowShowCommand::WindowShowCommand(Window* v, const Param& p) : WindowCommand(v, p)
    {
    }
    
    WindowShowCommand::WindowShowCommand(WindowID v, const Param& p) : WindowCommand(v, p)
    {
    }
    
    WindowShowCommand::~WindowShowCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WindowShowCommand::init_info()
    {
        auto w = writer<WindowShowCommand>();
        w.description("Window Show Command");
    }
}
