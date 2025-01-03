////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/WindowMoveCommand.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowMoveCommand)

namespace yq::tachyon {

    WindowMoveCommand::WindowMoveCommand(Window* v, const Vector2I& pos, const Param& p) : WindowCommand(v, p), m_position(pos)
    {
    }

    WindowMoveCommand::WindowMoveCommand(WindowID v, const Vector2I& pos, const Param& p) : WindowCommand(v, p), m_position(pos)
    {
    }
    
    WindowMoveCommand::~WindowMoveCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WindowMoveCommand::init_info()
    {
        auto w = writer<WindowMoveCommand>();
        w.description("Window Move Command");
        w.property("position", &WindowMoveCommand::position).description("New position");
        w.property("x", &WindowMoveCommand::x).description("New X position");
        w.property("y", &WindowMoveCommand::y).description("New Y position");
    }
}
