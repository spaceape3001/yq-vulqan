////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/post/Command.hpp>

namespace yq::tachyon {
    class AppCommandInfo : public post::CommandInfo {
    public:
        AppCommandInfo(std::string_view zName, post::CommandInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class AppCommand : public post::Command {
        YQ_OBJECT_INFO(AppCommandInfo)
        YQ_OBJECT_DECLARE(AppCommand, post::Command)
    public:
    
        struct Param : public post::Command::Param {
        };
    
        AppCommand(const Param& p = {});
        virtual ~AppCommand();
        
        static void init_info();
    };
}
