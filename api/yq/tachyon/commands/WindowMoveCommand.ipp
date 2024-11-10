////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowMoveCommand.hpp"
#include <yq/post/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowMoveCommand)

namespace yq::tachyon {

    WindowMoveCommand::WindowMoveCommand(Viewer* v, const Vector2I& pos, const Param& p) : WindowCommand(v, p), m_position(pos)
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
