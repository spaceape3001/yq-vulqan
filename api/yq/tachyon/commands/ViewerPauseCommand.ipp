////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViewerPauseCommand.hpp"
#include <yq/post/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerPauseCommand)

namespace yq::tachyon {

    ViewerPauseCommand::ViewerPauseCommand(Viewer* v, const Param& p) : ViewerCommand(v, p)
    {
    }
    
    ViewerPauseCommand::~ViewerPauseCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ViewerPauseCommand::init_info()
    {
        auto w = writer<ViewerPauseCommand>();
        w.description("Viewer Pause Command");
    }
}
