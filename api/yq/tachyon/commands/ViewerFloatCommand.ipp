////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViewerFloatCommand.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerFloatCommand)

namespace yq::tachyon {

    ViewerFloatCommand::ViewerFloatCommand(Viewer* v, const Param& p) : ViewerCommand(v, p)
    {
    }
    
    ViewerFloatCommand::~ViewerFloatCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ViewerFloatCommand::init_info()
    {
        auto w = writer<ViewerFloatCommand>();
        w.description("Viewer Float (ie always on top) Command");
    }
}
