////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/ViewerHideCommand.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

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
