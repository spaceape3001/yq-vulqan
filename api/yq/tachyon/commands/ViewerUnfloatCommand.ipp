////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViewerUnfloatCommand.hpp"
#include <yq/post/CommandInfoWriter.hpp>

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
