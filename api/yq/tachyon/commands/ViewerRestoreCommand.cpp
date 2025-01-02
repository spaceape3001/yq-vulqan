////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViewerRestoreCommand.hpp"
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerRestoreCommand)

namespace yq::tachyon {

    ViewerRestoreCommand::ViewerRestoreCommand(Viewer* v, const Param& p) : ViewerCommand(v, p)
    {
    }
    
    ViewerRestoreCommand::ViewerRestoreCommand(ViewerID v, const Param& p) : ViewerCommand(v, p)
    {
    }
    
    ViewerRestoreCommand::~ViewerRestoreCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ViewerRestoreCommand::init_info()
    {
        auto w = writer<ViewerRestoreCommand>();
        w.description("Viewer Restore Command");
    }
}
