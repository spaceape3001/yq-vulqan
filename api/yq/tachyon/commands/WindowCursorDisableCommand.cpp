////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowCursorDisableCommand.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowCursorDisableCommand)

namespace yq::tachyon {

    WindowCursorDisableCommand::WindowCursorDisableCommand(Window* v, const Param& p) : WindowCommand(v, p)
    {
    }
    
    WindowCursorDisableCommand::WindowCursorDisableCommand(WindowID v, const Param& p) : WindowCommand(v, p)
    {
    }

    WindowCursorDisableCommand::~WindowCursorDisableCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WindowCursorDisableCommand::init_info()
    {
        auto w = writer<WindowCursorDisableCommand>();
        w.description("Window Cursor Disable Command");
    }
}
