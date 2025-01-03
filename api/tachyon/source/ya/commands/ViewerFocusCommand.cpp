////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/ViewerFocusCommand.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerFocusCommand)

namespace yq::tachyon {

    ViewerFocusCommand::ViewerFocusCommand(Viewer* v, const Param& p) : ViewerCommand(v, p)
    {
    }
    
    ViewerFocusCommand::~ViewerFocusCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ViewerFocusCommand::init_info()
    {
        auto w = writer<ViewerFocusCommand>();
        w.description("Viewer Focus Command");
    }
}
