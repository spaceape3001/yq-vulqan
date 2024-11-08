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
    
        GLFWCloseCommand(Viewer*, const Param& p = {});
        virtual ~GLFWCloseCommand();
        
        static void init_info();
        
        Viewer* viewer() const { return m_viewer; }
    private:
        Viewer* const m_viewer;
    };
}
