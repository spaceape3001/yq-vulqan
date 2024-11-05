////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViewerCloseCommand.hpp"
#include <yq/post/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerCloseCommand)

namespace yq::tachyon {

    ViewerCloseCommand::ViewerCloseCommand(ViewerPtr v, const Param& p) : ViewerCommand(v, p)
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
