////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Command.hpp>
#include <yq/tachyon/api/ControllerBind.hpp>

namespace yq::tachyon {
    class Controller;

    class ControllerCommandInfo : public CommandInfo {
    public:
        ControllerCommandInfo(std::string_view zName, CommandInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class ControllerCommand : public Command, public ControllerBind {
        YQ_OBJECT_INFO(ControllerCommandInfo)
        YQ_OBJECT_DECLARE(ControllerCommand, Command)
    public:
    
        struct Param : public Command::Param {
        };
    
        ControllerCommand(ControllerID, const Param& p = {});
        ControllerCommand(Controller*, const Param& p = {});
        virtual ~ControllerCommand();
        
        static void init_info();
    };
}
