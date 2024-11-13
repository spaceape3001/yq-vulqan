////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MouseHideCommand.hpp"
#include <yq/tachyon/post/CommandInfoWriter.hpp>

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
}
