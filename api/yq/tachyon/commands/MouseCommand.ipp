////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MouseCommand.hpp"

#include <yq/post/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MouseCommand)

namespace yq::tachyon {
    MouseCommandInfo::MouseCommandInfo(std::string_view zName, post::CommandInfo& base, const std::source_location& sl) :
        post::CommandInfo(zName, base, sl)
    {
    }

    ////////////////////////////////////////////////////////////////////////////

    MouseCommand::MouseCommand(Viewer* v, const Param& p) : post::Command(p), ViewerBind(v)
    {
    }
    
    MouseCommand::~MouseCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void MouseCommand::init_info()
    {
        auto w = writer<MouseCommand>();
        w.description("Mouse command base class");
    }
}
