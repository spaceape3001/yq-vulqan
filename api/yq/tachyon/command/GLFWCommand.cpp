////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/command/GLFWCommand.hpp>

#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::GLFWCommand)

namespace yq::tachyon {
    GLFWCommandMeta::GLFWCommandMeta(std::string_view zName, CommandMeta& base, const std::source_location& sl) :
        CommandMeta(zName, base, sl)
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

    void GLFWCommand::init_meta()
    {
        auto w = writer<GLFWCommand>();
        w.description("GLFW command base class");
    }
}
