////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/ViewerUnfloatCommand.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerUnfloatCommand)

namespace yq::tachyon {

    ViewerUnfloatCommand::ViewerUnfloatCommand(Viewer* v, const Param& p) : ViewerCommand(v, p)
    {
    }
    
    ViewerUnfloatCommand::~ViewerUnfloatCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ViewerUnfloatCommand::init_info()
    {
        auto w = writer<ViewerUnfloatCommand>();
        w.description("Viewer Unfloat Command (ie, remove always-on-top");
    }
}