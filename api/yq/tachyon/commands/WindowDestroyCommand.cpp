////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowDestroyCommand.hpp"
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowDestroyCommand)

namespace yq::tachyon {

    WindowDestroyCommand::WindowDestroyCommand(Window* v, const Param& p) : WindowCommand(v, p)
    {
    }
    
    WindowDestroyCommand::WindowDestroyCommand(WindowID v, const Param& p) : WindowCommand(v, p)
    {
    }

    WindowDestroyCommand::~WindowDestroyCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WindowDestroyCommand::init_info()
    {
        auto w = writer<WindowDestroyCommand>();
        w.description("Window Destroy Command");
    }
}
