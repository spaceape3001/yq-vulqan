////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/ViewerCommand.hpp>

namespace yq::tachyon {
    class MouseNormalCommand : public ViewerCommand {
        YQ_OBJECT_DECLARE(MouseNormalCommand, ViewerCommand)
    public:
    
        struct Param : public ViewerCommand::Param {
        };
    
        MouseNormalCommand(Viewer*, const Param& p = {});
        virtual ~MouseNormalCommand();
        
        static void init_info();
    };
}
