////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowFocusCommand.hpp"
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowFocusCommand)

namespace yq::tachyon {

    WindowFocusCommand::WindowFocusCommand(Window* v, const Param& p) : WindowCommand(v, p)
    {
    }

    WindowFocusCommand::WindowFocusCommand(WindowID v, const Param& p) : WindowCommand(v, p)
    {
    }
    
    WindowFocusCommand::~WindowFocusCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WindowFocusCommand::init_info()
    {
        auto w = writer<WindowFocusCommand>();
        w.description("Window Focus Command");
    }
}
