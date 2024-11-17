////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViewerMaximizeCommand.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

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
