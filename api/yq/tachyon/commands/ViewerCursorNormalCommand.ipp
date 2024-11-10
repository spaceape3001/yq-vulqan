////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViewerCursorNormalCommand.hpp"
#include <yq/post/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerCursorNormalCommand)

namespace yq::tachyon {

    ViewerCursorNormalCommand::ViewerCursorNormalCommand(Viewer* v, const Param& p) : ViewerCommand(v, p)
    {
    }
    
    ViewerCursorNormalCommand::~ViewerCursorNormalCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ViewerCursorNormalCommand::init_info()
    {
        auto w = writer<ViewerCursorNormalCommand>();
        w.description("Viewer Cursor Normal Command");
    }
}
