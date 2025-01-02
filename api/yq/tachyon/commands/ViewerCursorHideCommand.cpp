////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViewerCursorHideCommand.hpp"
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerCursorHideCommand)

namespace yq::tachyon {

    ViewerCursorHideCommand::ViewerCursorHideCommand(Viewer* v, const Param& p) : ViewerCommand(v, p)
    {
    }
    
    ViewerCursorHideCommand::~ViewerCursorHideCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ViewerCursorHideCommand::init_info()
    {
        auto w = writer<ViewerCursorHideCommand>();
        w.description("Viewer Cursor Hide Command");
    }
}
