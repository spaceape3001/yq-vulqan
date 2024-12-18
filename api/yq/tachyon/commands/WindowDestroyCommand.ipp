////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowDestroyCommand.hpp"
#include <yq/post/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowDestroyCommand)

namespace yq::tachyon {

    WindowDestroyCommand::WindowDestroyCommand(Viewer* v, const Param& p) : WindowCommand(v, p)
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
