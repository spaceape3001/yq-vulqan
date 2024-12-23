////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowCursorCaptureCommand.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowCursorCaptureCommand)

namespace yq::tachyon {

    WindowCursorCaptureCommand::WindowCursorCaptureCommand(Window* v, const Param& p) : WindowCommand(v, p)
    {
    }
    
    WindowCursorCaptureCommand::~WindowCursorCaptureCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WindowCursorCaptureCommand::init_info()
    {
        auto w = writer<WindowCursorCaptureCommand>();
        w.description("Window Cursor Capture Command");
    }
}
