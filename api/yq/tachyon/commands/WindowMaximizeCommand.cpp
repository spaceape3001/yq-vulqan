////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowMaximizeCommand.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowMaximizeCommand)

namespace yq::tachyon {

    WindowMaximizeCommand::WindowMaximizeCommand(Window* v, const Param& p) : WindowCommand(v, p)
    {
    }
    
    WindowMaximizeCommand::WindowMaximizeCommand(WindowID v, const Param& p) : WindowCommand(v, p)
    {
    }

    WindowMaximizeCommand::~WindowMaximizeCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WindowMaximizeCommand::init_info()
    {
        auto w = writer<WindowMaximizeCommand>();
        w.description("Window Maximize Command");
    }
}
