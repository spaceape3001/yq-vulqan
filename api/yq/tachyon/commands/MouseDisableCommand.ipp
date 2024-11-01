////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MouseDisableCommand.hpp"
#include <yq/post/CommandInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MouseDisableCommand)

namespace yq::tachyon {

    MouseDisableCommand::MouseDisableCommand(Viewer* v, const Param& p) : ViewerCommand(v, p)
    {
    }
    
    MouseDisableCommand::~MouseDisableCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void MouseDisableCommand::init_info()
    {
        auto w = writer<MouseDisableCommand>();
        w.description("Mouse Disable Command");
    }
    
    YQ_INVOKE(MouseDisableCommand::init_info();)
}
