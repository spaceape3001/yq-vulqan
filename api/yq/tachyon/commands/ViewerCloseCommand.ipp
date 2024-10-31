////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViewerCloseCommand.hpp"
#include <yq/post/CommandInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

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
    
    YQ_INVOKE(ViewerCloseCommand::init_info();)
}
