////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowShowCommand.hpp"
#include <yq/post/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowShowCommand)

namespace yq::tachyon {

    WindowShowCommand::WindowShowCommand(Viewer* v, const Param& p) : WindowCommand(v, p)
    {
    }
    
    WindowShowCommand::~WindowShowCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WindowShowCommand::init_info()
    {
        auto w = writer<WindowShowCommand>();
        w.description("Window Show Command");
    }
}
