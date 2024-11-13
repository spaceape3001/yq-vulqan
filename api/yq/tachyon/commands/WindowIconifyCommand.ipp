////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowIconifyCommand.hpp"
#include <yq/tachyon/post/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowIconifyCommand)

namespace yq::tachyon {

    WindowIconifyCommand::WindowIconifyCommand(Viewer* v, const Param& p) : WindowCommand(v, p)
    {
    }
    
    WindowIconifyCommand::~WindowIconifyCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WindowIconifyCommand::init_info()
    {
        auto w = writer<WindowIconifyCommand>();
        w.description("Window Iconify Command");
    }
}
