////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MouseCaptureCommand.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

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
