////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowFloatCommand.hpp"
#include <yq/post/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowFloatCommand)

namespace yq::tachyon {

    WindowFloatCommand::WindowFloatCommand(Viewer* v, const Param& p) : WindowCommand(v, p)
    {
    }
    
    WindowFloatCommand::~WindowFloatCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WindowFloatCommand::init_info()
    {
        auto w = writer<WindowFloatCommand>();
        w.description("Window Float (ie always on top) Command");
    }
}
