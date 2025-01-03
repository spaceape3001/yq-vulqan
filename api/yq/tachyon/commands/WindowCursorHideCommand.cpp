////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowCursorHideCommand.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowCursorHideCommand)

namespace yq::tachyon {

    WindowCursorHideCommand::WindowCursorHideCommand(Window* v, const Param& p) : WindowCommand(v, p)
    {
    }
    
    WindowCursorHideCommand::WindowCursorHideCommand(WindowID v, const Param& p) : WindowCommand(v, p)
    {
    }

    WindowCursorHideCommand::~WindowCursorHideCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WindowCursorHideCommand::init_info()
    {
        auto w = writer<WindowCursorHideCommand>();
        w.description("Window Cursor Hide Command");
    }
}
