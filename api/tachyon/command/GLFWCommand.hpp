////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Command.hpp>

namespace yq::tachyon {
    class GLFWCommandMeta : public CommandMeta {
    public:
        GLFWCommandMeta(std::string_view zName, CommandMeta& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class GLFWCommand : public Command {
        YQ_OBJECT_INFO(GLFWCommandMeta)
        YQ_OBJECT_DECLARE(GLFWCommand, Command)
    public:
    
        struct Param : public Command::Param {
        };
    
        GLFWCommand(const Param& p = {});
        virtual ~GLFWCommand();
        
        static void init_info();
    };
}
