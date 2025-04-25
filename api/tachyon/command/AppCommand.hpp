////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/msg/Command.hpp>

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

        static void init_info();

    protected:
        AppCommand(const Header& h={});
        AppCommand(const AppCommand&, const Header& h={});
        virtual ~AppCommand();
        
    private:
        AppCommand(AppCommand&&) = delete;
        AppCommand& operator=(const AppCommand&) = delete;
        AppCommand& operator=(AppCommand&&) = delete;
    };
}
