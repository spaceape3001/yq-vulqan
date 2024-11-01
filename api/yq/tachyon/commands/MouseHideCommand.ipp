////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MouseHideCommand.hpp"
#include <yq/post/CommandInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MouseHideCommand)

namespace yq::tachyon {

    MouseHideCommand::MouseHideCommand(Viewer* v, const Param& p) : ViewerCommand(v, p)
    {
    }
    
    MouseHideCommand::~MouseHideCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void MouseHideCommand::init_info()
    {
        auto w = writer<MouseHideCommand>();
        w.description("Mouse Hide Command");
    }
    
    YQ_INVOKE(MouseHideCommand::init_info();)
}
