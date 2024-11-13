////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowMaximizeCommand.hpp"
#include <yq/tachyon/post/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowMaximizeCommand)

namespace yq::tachyon {

    WindowMaximizeCommand::WindowMaximizeCommand(Viewer* v, const Param& p) : WindowCommand(v, p)
    {
    }
    
    WindowMaximizeCommand::~WindowMaximizeCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WindowMaximizeCommand::init_info()
    {
        auto w = writer<WindowMaximizeCommand>();
        w.description("Window Maximize Command");
    }
}
