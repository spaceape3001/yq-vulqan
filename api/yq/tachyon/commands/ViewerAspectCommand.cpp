////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViewerAspectCommand.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerAspectCommand)

namespace yq::tachyon {

    ViewerAspectCommand::ViewerAspectCommand(Viewer* v, const Size2I& asp, const Param& p) : ViewerCommand(v, p), m_aspect(asp)
    {
    }
    
    ViewerAspectCommand::~ViewerAspectCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ViewerAspectCommand::init_info()
    {
        auto w = writer<ViewerAspectCommand>();
        w.description("Viewer Aspect Command");
        w.property("aspect", &ViewerAspectCommand::aspect).description("Aspect ratio");
        w.property("width", &ViewerAspectCommand::width).description("Aspect width").alias("w");
        w.property("height", &ViewerAspectCommand::height).description("Aspect height").alias("h");
    }
}
