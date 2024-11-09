////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowAttentionCommand.hpp"
#include <yq/post/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowAttentionCommand)

namespace yq::tachyon {

    WindowAttentionCommand::WindowAttentionCommand(Viewer* v, const Param& p) : WindowCommand(v, p)
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
