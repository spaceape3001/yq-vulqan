////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViewerRestoreCommand.hpp"
#include <yq/post/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerRestoreCommand)

namespace yq::tachyon {

    ViewerRestoreCommand::ViewerRestoreCommand(Viewer* v, const Param& p) : ViewerCommand(v, p)
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
