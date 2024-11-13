////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/post/Command.hpp>
#include <yq/tachyon/core/TachyonBind.hpp>

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
    
        TachyonCommand(Tachyon*, const Param& p = {});
        virtual ~TachyonCommand();
        
        static void init_info();
    };
}
