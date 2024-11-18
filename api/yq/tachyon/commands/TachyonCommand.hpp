////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Command.hpp>
#include <yq/tachyon/api/TachyonBind.hpp>
#include <yq/tachyon/typedef/tachyon.hpp>

namespace yq::tachyon {
    class Tachyon;

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
    
        TachyonCommand(const Tachyon*, const Param& p = {});
        TachyonCommand(TachyonID, const Param& p = {});
        virtual ~TachyonCommand();
        
        static void init_info();
    };
}
