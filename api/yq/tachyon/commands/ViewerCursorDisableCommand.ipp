////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViewerCursorDisableCommand.hpp"
#include <yq/post/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerCursorDisableCommand)

namespace yq::tachyon {

    ViewerCursorDisableCommand::ViewerCursorDisableCommand(Viewer* v, const Param& p) : ViewerCommand(v, p)
    {
    }
    
    ViewerCursorDisableCommand::~ViewerCursorDisableCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ViewerCursorDisableCommand::init_info()
    {
        auto w = writer<ViewerCursorDisableCommand>();
        w.description("Viewer Cursor Disable Command");
    }
}
