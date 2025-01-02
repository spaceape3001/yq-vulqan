////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViewerCloseCommand.hpp"
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerCloseCommand)

namespace yq::tachyon {

    ViewerCloseCommand::ViewerCloseCommand(Viewer* v, const Param& p) : ViewerCommand(v, p)
    {
    }
    
    ViewerCloseCommand::~ViewerCloseCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ViewerCloseCommand::init_info()
    {
        auto w = writer<ViewerCloseCommand>();
        w.description("Viewer Close Command");
    }
}
