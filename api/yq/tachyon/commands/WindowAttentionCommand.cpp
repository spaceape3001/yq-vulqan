////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowAttentionCommand.hpp"
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowAttentionCommand)

namespace yq::tachyon {

    WindowAttentionCommand::WindowAttentionCommand(WindowID v, const Param& p) : WindowCommand(v, p)
    {
    }

    WindowAttentionCommand::WindowAttentionCommand(Window* v, const Param& p) : WindowCommand(v, p)
    {
    }
    
    WindowAttentionCommand::~WindowAttentionCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WindowAttentionCommand::init_info()
    {
        auto w = writer<WindowAttentionCommand>();
        w.description("Window Attention Command");
    }
}
