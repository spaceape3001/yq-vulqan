////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/msg/Command.hpp>

namespace yq::tachyon {
    class GLFWCommandInfo : public CommandInfo {
    public:
        GLFWCommandInfo(std::string_view zName, CommandInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class GLFWCommand : public Command {
        YQ_OBJECT_INFO(GLFWCommandInfo)
        YQ_OBJECT_DECLARE(GLFWCommand, Command)
    public:
    
        struct Param : public Command::Param {
        };
    
        GLFWCommand(const Param& p = {});
        virtual ~GLFWCommand();
        
        static void init_info();
    };
}
