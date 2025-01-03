////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/ViewerResumeCommand.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerResumeCommand)

namespace yq::tachyon {

    ViewerResumeCommand::ViewerResumeCommand(Viewer* v, const Param& p) : ViewerCommand(v, p)
    {
    }
    
    ViewerResumeCommand::~ViewerResumeCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ViewerResumeCommand::init_info()
    {
        auto w = writer<ViewerResumeCommand>();
        w.description("Viewer Resume Command");
    }
}