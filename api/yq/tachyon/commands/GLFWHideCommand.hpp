////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/GLFWCommand.hpp>

namespace yq::tachyon {
    class Viewer;

    class GLFWHideCommand : public GLFWCommand {
        YQ_OBJECT_DECLARE(GLFWHideCommand, GLFWCommand)
    public:
    
        struct Param : public GLFWCommand::Param {
        };
    
        GLFWHideCommand(ViewerPtr, const Param& p = {});
        virtual ~GLFWHideCommand();
        
        static void init_info();
        
        ViewerPtr viewer() const { return m_viewer; }
    private:
        ViewerPtr const m_viewer;
    };
}
