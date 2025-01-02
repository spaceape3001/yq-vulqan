////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Command.hpp>
#include <yt/os/WindowBind.hpp>

namespace yq::tachyon {
    class WindowCommandInfo : public CommandInfo {
    public:
        WindowCommandInfo(std::string_view zName, CommandInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class WindowCommand : public Command, public WindowBind {
        YQ_OBJECT_INFO(WindowCommandInfo)
        YQ_OBJECT_DECLARE(WindowCommand, Command)
    public:
    
        struct Param : public Command::Param {
        };
    
        WindowCommand(const Window*, const Param& p = {});
        WindowCommand(WindowID, const Param& p = {});
        virtual ~WindowCommand();
        
        static void init_info();
    };
}
