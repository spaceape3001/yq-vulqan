////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/WindowHideCommand.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowHideCommand)

namespace yq::tachyon {

    WindowHideCommand::WindowHideCommand(Window* v, const Param& p) : WindowCommand(v, p)
    {
    }

    WindowHideCommand::WindowHideCommand(WindowID v, const Param& p) : WindowCommand(v, p)
    {
    }
    
    WindowHideCommand::~WindowHideCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WindowHideCommand::init_info()
    {
        auto w = writer<WindowHideCommand>();
        w.description("Window Hide Command");
    }
}
