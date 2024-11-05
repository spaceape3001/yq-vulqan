////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/post/Command.hpp>

namespace yq::tachyon {
    class GLFWCommandInfo : public post::CommandInfo {
    public:
        GLFWCommandInfo(std::string_view zName, post::CommandInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class GLFWCommand : public post::Command {
        YQ_OBJECT_INFO(GLFWCommandInfo)
        YQ_OBJECT_DECLARE(GLFWCommand, post::Command)
    public:
    
        struct Param : public post::Command::Param {
        };
    
        GLFWCommand(const Param& p = {});
        virtual ~GLFWCommand();
        
        static void init_info();
    };
}
