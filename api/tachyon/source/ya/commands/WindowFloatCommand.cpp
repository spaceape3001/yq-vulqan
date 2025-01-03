////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/WindowFloatCommand.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowFloatCommand)

namespace yq::tachyon {

    WindowFloatCommand::WindowFloatCommand(Window* v, const Param& p) : WindowCommand(v, p)
    {
    }
    
    WindowFloatCommand::WindowFloatCommand(WindowID v, const Param& p) : WindowCommand(v, p)
    {
    }

    WindowFloatCommand::~WindowFloatCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WindowFloatCommand::init_info()
    {
        auto w = writer<WindowFloatCommand>();
        w.description("Window Float (ie always on top) Command");
    }
}