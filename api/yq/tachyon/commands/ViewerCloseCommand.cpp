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

    static void reg_viewer_close_command()
    {
        {
            auto w = writer<ViewerCloseCommand>();
            w.description("Viewer Close Command");
        }
    }
    
    YQ_INVOKE(reg_viewer_close_command();)
}
