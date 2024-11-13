////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViewerHideCommand.hpp"
#include <yq/tachyon/post/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerHideCommand)

namespace yq::tachyon {

    ViewerHideCommand::ViewerHideCommand(Viewer* v, const Param& p) : ViewerCommand(v, p)
    {
    }
    
    ViewerHideCommand::~ViewerHideCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ViewerHideCommand::init_info()
    {
        auto w = writer<ViewerHideCommand>();
        w.description("Viewer Hide Command");
    }
}
