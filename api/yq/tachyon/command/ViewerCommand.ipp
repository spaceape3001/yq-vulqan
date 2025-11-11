////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/command/ViewerCommand.hpp>

#include <yq/tachyon/api/CommandMetaWriter.hpp>

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
