////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowFocusCommand.hpp"
#include <yq/tachyon/post/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowFocusCommand)

namespace yq::tachyon {

    WindowFocusCommand::WindowFocusCommand(Viewer* v, const Param& p) : WindowCommand(v, p)
    {
    }
    
    WindowFocusCommand::~WindowFocusCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WindowFocusCommand::init_info()
    {
        auto w = writer<WindowFocusCommand>();
        w.description("Window Focus Command");
    }
}
