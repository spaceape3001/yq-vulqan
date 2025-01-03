////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowUnfloatCommand.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowUnfloatCommand)

namespace yq::tachyon {

    WindowUnfloatCommand::WindowUnfloatCommand(Window* v, const Param& p) : WindowCommand(v, p)
    {
    }
    
    WindowUnfloatCommand::WindowUnfloatCommand(WindowID v, const Param& p) : WindowCommand(v, p)
    {
    }

    WindowUnfloatCommand::~WindowUnfloatCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WindowUnfloatCommand::init_info()
    {
        auto w = writer<WindowUnfloatCommand>();
        w.description("Window Unfloat Command (ie, remove always-on-top");
    }
}
