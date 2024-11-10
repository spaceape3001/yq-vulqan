////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowUnfloatCommand.hpp"
#include <yq/post/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowUnfloatCommand)

namespace yq::tachyon {

    WindowUnfloatCommand::WindowUnfloatCommand(Viewer* v, const Param& p) : WindowCommand(v, p)
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
