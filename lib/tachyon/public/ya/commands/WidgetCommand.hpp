////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/msg/Command.hpp>
#include <yt/ui/WidgetBind.hpp>

namespace yq::tachyon {
    class WidgetCommandInfo : public CommandInfo {
    public:
        WidgetCommandInfo(std::string_view zName, CommandInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class WidgetCommand : public Command, public WidgetBind {
        YQ_OBJECT_INFO(WidgetCommandInfo)
        YQ_OBJECT_DECLARE(WidgetCommand, Command)
    public:
    
        struct Param : public Command::Param {
        };
    
        WidgetCommand(const Widget*, const Param& p = {});
        WidgetCommand(WidgetID, const Param& p = {});
        virtual ~WidgetCommand();
        
        static void init_info();
    };
}
