////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Command.hpp>
#include <yq/tachyon/app/ViewerBind.hpp>

namespace yq::tachyon {
    class MouseCommandInfo : public CommandInfo {
    public:
        MouseCommandInfo(std::string_view zName, CommandInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class MouseCommand : public Command, public ViewerBind {
        YQ_OBJECT_INFO(MouseCommandInfo)
        YQ_OBJECT_DECLARE(MouseCommand, Command)
    public:
    
        struct Param : public Command::Param {
        };
    
        MouseCommand(const Viewer*, const Param& p = {});
        MouseCommand(ViewerID, const Param& p = {});
        virtual ~MouseCommand();
        
        static void init_info();
    };
}
