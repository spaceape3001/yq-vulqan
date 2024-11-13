////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViewerCursorHideCommand.hpp"
#include <yq/tachyon/post/CommandInfoWriter.hpp>

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
