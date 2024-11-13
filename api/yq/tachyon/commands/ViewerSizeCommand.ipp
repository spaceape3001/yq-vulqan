////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViewerSizeCommand.hpp"

#include <yq/tachyon/post/CommandInfoWriter.hpp>
#include <yq/strings.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerSizeCommand)

namespace yq::tachyon {

    ViewerSizeCommand::ViewerSizeCommand(Viewer* v, const Size2I& sz, const Param& p) : ViewerCommand(v, p), m_size(sz)
    {
    }
    
    ViewerSizeCommand::~ViewerSizeCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ViewerSizeCommand::init_info()
    {
        auto w = writer<ViewerSizeCommand>();
        w.description("Viewer Size Command");
        w.property("size", &ViewerSizeCommand::size).description("New Size");
        w.property("width", &ViewerSizeCommand::width).description("New Width").alias("w");
        w.property("height", &ViewerSizeCommand::height).description("New Height").alias("h");
    }
}
