////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "GLFWCloseCommand.hpp"
#include <yq/post/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::GLFWCloseCommand)

namespace yq::tachyon {

    GLFWCloseCommand::GLFWCloseCommand(Viewer* v, const Param& p) : GLFWCommand(p), m_viewer(v)
    {
    }
    
    GLFWCloseCommand::~GLFWCloseCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void GLFWCloseCommand::init_info()
    {
        auto w = writer<GLFWCloseCommand>();
        w.description("GLFW Close Command");
    }
}
