////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "GLFWCommand.hpp"

#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::GLFWCommand)

namespace yq::tachyon {
    GLFWCommandInfo::GLFWCommandInfo(std::string_view zName, CommandInfo& base, const std::source_location& sl) :
        CommandInfo(zName, base, sl)
    {
    }

    ////////////////////////////////////////////////////////////////////////////

    GLFWCommand::GLFWCommand(const Param& p) : Command(p)
    {
    }
    
    GLFWCommand::~GLFWCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void GLFWCommand::init_info()
    {
        auto w = writer<GLFWCommand>();
        w.description("GLFW command base class");
    }
}
