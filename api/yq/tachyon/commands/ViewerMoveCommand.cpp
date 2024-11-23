////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViewerMoveCommand.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerMoveCommand)

namespace yq::tachyon {

    ViewerMoveCommand::ViewerMoveCommand(Viewer* v, const Vector2I& pos, const Param& p) : ViewerCommand(v, p), m_position(pos)
    {
    }
    
    ViewerMoveCommand::~ViewerMoveCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ViewerMoveCommand::init_info()
    {
        auto w = writer<ViewerMoveCommand>();
        w.description("Viewer Move Command");
        w.property("position", &ViewerMoveCommand::position).description("New position");
        w.property("x", &ViewerMoveCommand::x).description("New X position");
        w.property("y", &ViewerMoveCommand::y).description("New Y position");
    }
}
