////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/AppDeleteViewerCommand.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

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
