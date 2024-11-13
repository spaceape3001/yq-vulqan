////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViewerShowCommand.hpp"
#include <yq/tachyon/post/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerShowCommand)

namespace yq::tachyon {

    ViewerShowCommand::ViewerShowCommand(Viewer* v, const Param& p) : ViewerCommand(v, p)
    {
    }
    
    ViewerShowCommand::~ViewerShowCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ViewerShowCommand::init_info()
    {
        auto w = writer<ViewerShowCommand>();
        w.description("Viewer Show Command");
    }
}
