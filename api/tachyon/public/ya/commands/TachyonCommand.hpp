////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/msg/Command.hpp>
#include <yt/api/TachyonBind.hpp>
#include <yt/typedef/tachyon.hpp>

namespace yq::tachyon {
    class TachyonCommandInfo : public CommandInfo {
    public:
        TachyonCommandInfo(std::string_view zName, CommandInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class TachyonCommand : public Command, public TachyonBind {
        YQ_OBJECT_INFO(TachyonCommandInfo)
        YQ_OBJECT_DECLARE(TachyonCommand, Command)
    public:
    
        struct Param : public Command::Param {
        };
    
        TachyonCommand(TachyonID, const Param& p = {});
        TachyonCommand(Tachyon*, const Param& p = {});
        virtual ~TachyonCommand();
        
        static void init_info();
    };
}