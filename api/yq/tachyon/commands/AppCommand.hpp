////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/post/Command.hpp>

namespace yq::tachyon {
    class AppCommandInfo : public CommandInfo {
    public:
        AppCommandInfo(std::string_view zName, CommandInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class AppCommand : public Command {
        YQ_OBJECT_INFO(AppCommandInfo)
        YQ_OBJECT_DECLARE(AppCommand, Command)
    public:
    
        struct Param : public Command::Param {
        };
    
        AppCommand(const Param& p = {});
        virtual ~AppCommand();
        
        static void init_info();
    };
}
