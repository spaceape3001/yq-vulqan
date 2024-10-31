////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViewerAttentionCommand.hpp"
#include <yq/post/CommandInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerAttentionCommand)

namespace yq::tachyon {

    ViewerAttentionCommand::ViewerAttentionCommand(Viewer* v, const Param& p) : ViewerCommand(v, p)
    {
    }
    
    ViewerAttentionCommand::~ViewerAttentionCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ViewerAttentionCommand::init_info()
    {
        auto w = writer<ViewerAttentionCommand>();
        w.description("Viewer Attention Command");
    }
    
    YQ_INVOKE(ViewerAttentionCommand::init_info();)
}
