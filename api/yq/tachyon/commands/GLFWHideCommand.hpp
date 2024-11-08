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
    
        GLFWHideCommand(Viewer*, const Param& p = {});
        virtual ~GLFWHideCommand();
        
        static void init_info();
        
        Viewer* viewer() const { return m_viewer; }
    private:
        Viewer* const m_viewer;
    };
}
