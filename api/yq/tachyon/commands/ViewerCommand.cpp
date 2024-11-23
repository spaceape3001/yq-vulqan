////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViewerCommand.hpp"

#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerCommand)

namespace yq::tachyon {
    ViewerCommandInfo::ViewerCommandInfo(std::string_view zName, CommandInfo& base, const std::source_location& sl) :
        CommandInfo(zName, base, sl)
    {
    }

    ////////////////////////////////////////////////////////////////////////////

    ViewerCommand::ViewerCommand(const Viewer* v, const Param& p) : Command(p), ViewerBind(v)
    {
    }
    
    ViewerCommand::ViewerCommand(ViewerID v, const Param& p) : Command(p), ViewerBind(v)
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
