////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViewerCommand.hpp"

#include <yq/post/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerCommand)

namespace yq::tachyon {
    ViewerCommandInfo::ViewerCommandInfo(std::string_view zName, post::CommandInfo& base, const std::source_location& sl) :
        post::CommandInfo(zName, base, sl)
    {
    }

    ////////////////////////////////////////////////////////////////////////////

    ViewerCommand::ViewerCommand(Viewer* v, const Param& p) : post::Command(p), ViewerBind(v)
    {
    }
    
    ViewerCommand::~ViewerCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ViewerCommand::init_info()
    {
        auto w = writer<ViewerCommand>();
        w.description("Viewer command base class");
    }
}
