////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowHideCommand.hpp"
#include <yq/tachyon/post/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowHideCommand)

namespace yq::tachyon {

    WindowHideCommand::WindowHideCommand(Viewer* v, const Param& p) : WindowCommand(v, p)
    {
    }
    
    WindowHideCommand::~WindowHideCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WindowHideCommand::init_info()
    {
        auto w = writer<WindowHideCommand>();
        w.description("Window Hide Command");
    }
}
