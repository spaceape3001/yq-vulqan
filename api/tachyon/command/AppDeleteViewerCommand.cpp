////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/AppDeleteViewerCommand.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AppDeleteViewerCommand)

namespace yq::tachyon {

    AppDeleteViewerCommand::AppDeleteViewerCommand(Viewer* v) : m_viewer(v)
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
