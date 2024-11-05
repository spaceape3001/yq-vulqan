////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/GLFWCommand.hpp>

namespace yq::tachyon {
    class Viewer;

    class GLFWCloseCommand : public GLFWCommand {
        YQ_OBJECT_DECLARE(GLFWCloseCommand, GLFWCommand)
    public:
    
        struct Param : public GLFWCommand::Param {
        };
    
        GLFWCloseCommand(ViewerPtr, const Param& p = {});
        virtual ~GLFWCloseCommand();
        
        static void init_info();
        
        ViewerPtr viewer() const { return m_viewer; }
    private:
        ViewerPtr const m_viewer;
    };
}
