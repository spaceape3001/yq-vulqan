////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViewerMaximizeCommand.hpp"
#include <yq/post/CommandInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

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
    
    YQ_INVOKE(ViewerMaximizeCommand::init_info();)
}
