////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViewerCursorCaptureCommand.hpp"
#include <yq/post/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerCursorCaptureCommand)

namespace yq::tachyon {

    ViewerCursorCaptureCommand::ViewerCursorCaptureCommand(Viewer* v, const Param& p) : ViewerCommand(v, p)
    {
    }
    
    ViewerCursorCaptureCommand::~ViewerCursorCaptureCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ViewerCursorCaptureCommand::init_info()
    {
        auto w = writer<ViewerCursorCaptureCommand>();
        w.description("Viewer Cursor Capture Command");
    }
}
