////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/ViewerCommand.hpp>

namespace yq::tachyon {
    class ViewerCursorCaptureCommand : public ViewerCommand {
        YQ_OBJECT_DECLARE(ViewerCursorCaptureCommand, ViewerCommand)
    public:
    
        struct Param : public ViewerCommand::Param {
        };
    
        ViewerCursorCaptureCommand(Viewer*, const Param& p = {});
        virtual ~ViewerCursorCaptureCommand();
        
        static void init_info();
    };
}
