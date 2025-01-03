////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/msg/Command.hpp>
#include <yt/api/ThreadBind.hpp>
#include <yt/typedef/tachyon.hpp>

namespace yq::tachyon {
    class ThreadCommandInfo : public CommandInfo {
    public:
        ThreadCommandInfo(std::string_view zName, CommandInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class ThreadCommand : public Command, public ThreadBind {
        YQ_OBJECT_INFO(ThreadCommandInfo)
        YQ_OBJECT_DECLARE(ThreadCommand, Command)
    public:
    
        struct Param : public Command::Param {
        };
    
        ThreadCommand(ThreadID, const Param& p = {});
        virtual ~ThreadCommand();
        
        static void init_info();
    };
}
