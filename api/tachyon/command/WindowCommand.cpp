////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/WindowCommand.hpp>

#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowCommand)

namespace yq::tachyon {
    WindowCommand::WindowCommand(const Header&h) : Command(h)
    {
    }
    
    WindowCommand::WindowCommand(const WindowCommand& cp, const Header&h) : Command(cp, h)
    {
    }
    
    WindowCommand::~WindowCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WindowCommand::init_info()
    {
        auto w = writer<WindowCommand>();
        w.description("Window command base class");
    }
}
