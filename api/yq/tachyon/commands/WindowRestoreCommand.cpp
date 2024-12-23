////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowRestoreCommand.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowRestoreCommand)

namespace yq::tachyon {

    WindowRestoreCommand::WindowRestoreCommand(Window* v, const Param& p) : WindowCommand(v, p)
    {
    }
    
    WindowRestoreCommand::~WindowRestoreCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WindowRestoreCommand::init_info()
    {
        auto w = writer<WindowRestoreCommand>();
        w.description("Window Restore Command");
    }
}
