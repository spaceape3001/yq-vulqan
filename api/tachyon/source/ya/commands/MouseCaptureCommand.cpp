////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/MouseCaptureCommand.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MouseCaptureCommand)

namespace yq::tachyon {

    MouseCaptureCommand::MouseCaptureCommand(Viewer* v, const Param& p) : ViewerCommand(v, p)
    {
    }
    
    MouseCaptureCommand::~MouseCaptureCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void MouseCaptureCommand::init_info()
    {
        auto w = writer<MouseCaptureCommand>();
        w.description("Mouse Capture Command");
    }
}