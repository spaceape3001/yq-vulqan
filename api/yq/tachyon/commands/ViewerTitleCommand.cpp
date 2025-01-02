////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViewerTitleCommand.hpp"
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ViewerTitleCommand)

namespace yq::tachyon {

    ViewerTitleCommand::ViewerTitleCommand(Viewer* v, std::string_view szTitle, const Param& p) : ViewerCommand(v, p), m_title(szTitle)
    {
    }
    
    ViewerTitleCommand::~ViewerTitleCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ViewerTitleCommand::init_info()
    {
        auto w = writer<ViewerTitleCommand>();
        w.description("Viewer Title Command");
        w.property("title", &ViewerTitleCommand::title).description("Viewer Title");
    }
}
