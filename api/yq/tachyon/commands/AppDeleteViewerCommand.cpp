////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AppDeleteViewerCommand.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AppDeleteViewerCommand)

namespace yq::tachyon {

    AppDeleteViewerCommand::AppDeleteViewerCommand(Viewer* v, const Param& p) : AppCommand(p), m_viewer(v)
    {
    }
    
    AppDeleteViewerCommand::~AppDeleteViewerCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void AppDeleteViewerCommand::init_info()
    {
        auto w = writer<AppDeleteViewerCommand>();
        w.description("App Delete Viewer Command");
    }
}
