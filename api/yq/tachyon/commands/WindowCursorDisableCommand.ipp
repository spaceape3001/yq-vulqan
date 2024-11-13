////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowCursorDisableCommand.hpp"
#include <yq/tachyon/post/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowCursorDisableCommand)

namespace yq::tachyon {

    WindowCursorDisableCommand::WindowCursorDisableCommand(Viewer* v, const Param& p) : WindowCommand(v, p)
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
