////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/WindowIconifyCommand.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowIconifyCommand)

namespace yq::tachyon {

    WindowIconifyCommand::WindowIconifyCommand(Window* v, const Param& p) : WindowCommand(v, p)
    {
    }
    
    WindowIconifyCommand::WindowIconifyCommand(WindowID v, const Param& p) : WindowCommand(v, p)
    {
    }

    WindowIconifyCommand::~WindowIconifyCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WindowIconifyCommand::init_info()
    {
        auto w = writer<WindowIconifyCommand>();
        w.description("Window Iconify Command");
    }
}
