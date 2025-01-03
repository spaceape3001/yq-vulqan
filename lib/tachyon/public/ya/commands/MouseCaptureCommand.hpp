////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/ViewerCommand.hpp>

namespace yq::tachyon {
    class MouseCaptureCommand : public ViewerCommand {
        YQ_OBJECT_DECLARE(MouseCaptureCommand, ViewerCommand)
    public:
    
        struct Param : public ViewerCommand::Param {
        };
    
        MouseCaptureCommand(Viewer*, const Param& p = {});
        virtual ~MouseCaptureCommand();
        
        static void init_info();
    };
}
