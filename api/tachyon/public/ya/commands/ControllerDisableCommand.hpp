////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/ControllerCommand.hpp>

namespace yq::tachyon {
    class ControllerDisableCommand : public ControllerCommand {
        YQ_OBJECT_DECLARE(ControllerDisableCommand, ControllerCommand)
    public:
    
        struct Param : public ControllerCommand::Param {
        };
    
        ControllerDisableCommand(Controller*, const Param& p = {});
        ControllerDisableCommand(ControllerID, const Param& p = {});
        virtual ~ControllerDisableCommand();
        
        static void init_info();
    };
}
