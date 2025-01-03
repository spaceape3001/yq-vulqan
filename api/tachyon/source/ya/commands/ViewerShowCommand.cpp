////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/ViewerShowCommand.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerShowCommand)

namespace yq::tachyon {

    ViewerShowCommand::ViewerShowCommand(Viewer* v, const Param& p) : ViewerCommand(v, p)
    {
    }
    
    ViewerShowCommand::~ViewerShowCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ViewerShowCommand::init_info()
    {
        auto w = writer<ViewerShowCommand>();
        w.description("Viewer Show Command");
    }
}