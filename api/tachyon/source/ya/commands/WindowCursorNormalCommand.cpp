////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/WindowCursorNormalCommand.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowCursorNormalCommand)

namespace yq::tachyon {

    WindowCursorNormalCommand::WindowCursorNormalCommand(Window* v, const Param& p) : WindowCommand(v, p)
    {
    }

    WindowCursorNormalCommand::WindowCursorNormalCommand(WindowID v, const Param& p) : WindowCommand(v, p)
    {
    }
    
    WindowCursorNormalCommand::~WindowCursorNormalCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WindowCursorNormalCommand::init_info()
    {
        auto w = writer<WindowCursorNormalCommand>();
        w.description("Window Cursor Normal Command");
    }
}
