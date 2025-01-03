////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/msg/Command.hpp>
#include <yt/app/ViewerBind.hpp>

namespace yq::tachyon {
    class Viewer;

    class ViewerCommandInfo : public CommandInfo {
    public:
        ViewerCommandInfo(std::string_view zName, CommandInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class ViewerCommand : public Command, public ViewerBind {
        YQ_OBJECT_INFO(ViewerCommandInfo)
        YQ_OBJECT_DECLARE(ViewerCommand, Command)
    public:
    
        struct Param : public Command::Param {
        };
    
        ViewerCommand(const Viewer*, const Param& p = {});
        ViewerCommand(ViewerID, const Param& p = {});
        virtual ~ViewerCommand();
        
        static void init_info();
    };
}
