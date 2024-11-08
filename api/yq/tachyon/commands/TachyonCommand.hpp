////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/post/Command.hpp>
#include <yq/tachyon/core/TachyonBind.hpp>

namespace yq::tachyon {
    class Tachyon;

    class TachyonCommandInfo : public post::CommandInfo {
    public:
        TachyonCommandInfo(std::string_view zName, post::CommandInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class TachyonCommand : public post::Command, public TachyonBind {
        YQ_OBJECT_INFO(TachyonCommandInfo)
        YQ_OBJECT_DECLARE(TachyonCommand, post::Command)
    public:
    
        struct Param : public post::Command::Param {
        };
    
        TachyonCommand(Tachyon*, const Param& p = {});
        virtual ~TachyonCommand();
        
        static void init_info();
    };
}
