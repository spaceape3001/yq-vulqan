////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "GLFWHideCommand.hpp"
#include <yq/post/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::GLFWHideCommand)

namespace yq::tachyon {

    GLFWHideCommand::GLFWHideCommand(Viewer* v, const Param& p) : GLFWCommand(p), m_viewer(v)
    {
    }
    
    GLFWHideCommand::~GLFWHideCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void GLFWHideCommand::init_info()
    {
        auto w = writer<GLFWHideCommand>();
        w.description("GLFW Hide Command");
    }
}
