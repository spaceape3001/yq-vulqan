////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/ViewerCommand.hpp>

namespace yq::tachyon {
    class MouseDisableCommand : public ViewerCommand {
        YQ_OBJECT_DECLARE(MouseDisableCommand, ViewerCommand)
    public:
    
        struct Param : public ViewerCommand::Param {
        };
    
        MouseDisableCommand(Viewer*, const Param& p = {});
        virtual ~MouseDisableCommand();
        
        static void init_info();
    };
}
