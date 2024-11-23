////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViewerIconifyCommand.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerIconifyCommand)

namespace yq::tachyon {

    ViewerIconifyCommand::ViewerIconifyCommand(Viewer* v, const Param& p) : ViewerCommand(v, p)
    {
    }
    
    ViewerIconifyCommand::~ViewerIconifyCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ViewerIconifyCommand::init_info()
    {
        auto w = writer<ViewerIconifyCommand>();
        w.description("Viewer Iconify Command");
    }
}
