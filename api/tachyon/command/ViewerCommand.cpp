////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/ViewerCommand.hpp>

#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerCommand)

namespace yq::tachyon {
    ViewerCommand::ViewerCommand(const Header&h) : Command(h)
    {
    }
    
    ViewerCommand::ViewerCommand(const ViewerCommand& cp, const Header&h) : Command(cp, h)
    {
    }


    ViewerCommand::~ViewerCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ViewerCommand::init_meta()
    {
        auto w = writer<ViewerCommand>();
        w.description("Viewer command base class");
    }
}
