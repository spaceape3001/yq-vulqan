////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/AppDeleteViewerCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AppDeleteViewerCommand)

namespace yq::tachyon {

    AppDeleteViewerCommand::AppDeleteViewerCommand(Viewer* v) : m_viewer(v)
    {
    }
    
    AppDeleteViewerCommand::~AppDeleteViewerCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void AppDeleteViewerCommand::init_meta()
    {
        auto w = writer<AppDeleteViewerCommand>();
        w.description("App Delete Viewer Command");
    }
}
