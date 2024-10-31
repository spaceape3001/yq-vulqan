////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViewerCommand.hpp"

#include <yq/post/CommandInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerCommand)

namespace yq::tachyon {
    ViewerCommandInfo::ViewerCommandInfo(std::string_view zName, post::CommandInfo& base, const std::source_location& sl) :
        post::CommandInfo(zName, base, sl)
    {
    }

    ////////////////////////////////////////////////////////////////////////////

    ViewerCommand::ViewerCommand(Viewer* v, const Param& p) : post::Command(p), m_viewer(v)
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
    
    YQ_INVOKE(ViewerCommand::init_info();)
}
