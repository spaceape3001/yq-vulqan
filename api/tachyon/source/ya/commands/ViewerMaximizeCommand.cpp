////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/ViewerMaximizeCommand.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerMaximizeCommand)

namespace yq::tachyon {

    ViewerMaximizeCommand::ViewerMaximizeCommand(Viewer* v, const Param& p) : ViewerCommand(v, p)
    {
    }
    
    ViewerMaximizeCommand::~ViewerMaximizeCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ViewerMaximizeCommand::init_info()
    {
        auto w = writer<ViewerMaximizeCommand>();
        w.description("Viewer Maximize Command");
    }
}
