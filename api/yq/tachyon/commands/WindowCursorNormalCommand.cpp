////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowCursorNormalCommand.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowCursorNormalCommand)

namespace yq::tachyon {

    WindowCursorNormalCommand::WindowCursorNormalCommand(Window* v, const Param& p) : WindowCommand(v, p)
    {
    }
    
    WindowCursorNormalCommand::~WindowCursorNormalCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WindowCursorNormalCommand::init_info()
    {
        auto w = writer<WindowCursorNormalCommand>();
        w.description("Window Cursor Normal Command");
    }
}
