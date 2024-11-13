////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MouseNormalCommand.hpp"
#include <yq/tachyon/post/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MouseNormalCommand)

namespace yq::tachyon {

    MouseNormalCommand::MouseNormalCommand(Viewer* v, const Param& p) : ViewerCommand(v, p)
    {
    }
    
    MouseNormalCommand::~MouseNormalCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void MouseNormalCommand::init_info()
    {
        auto w = writer<MouseNormalCommand>();
        w.description("Mouse Normal Command");
    }
}
