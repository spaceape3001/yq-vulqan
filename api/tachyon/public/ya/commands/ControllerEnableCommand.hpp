////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/ControllerCommand.hpp>

namespace yq::tachyon {
    class ControllerEnableCommand : public ControllerCommand {
        YQ_OBJECT_DECLARE(ControllerEnableCommand, ControllerCommand)
    public:
    
        struct Param : public ControllerCommand::Param {
        };
    
        ControllerEnableCommand(Controller*, const Param& p = {});
        ControllerEnableCommand(ControllerID, const Param& p = {});
        virtual ~ControllerEnableCommand();
        
        static void init_info();
    };
}
