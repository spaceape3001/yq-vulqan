////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/ViewerCommand.hpp>

namespace yq::tachyon {
    class ViewerCursorDisableCommand : public ViewerCommand {
        YQ_OBJECT_DECLARE(ViewerCursorDisableCommand, ViewerCommand)
    public:
    
        struct Param : public ViewerCommand::Param {
        };
    
        ViewerCursorDisableCommand(Viewer*, const Param& p = {});
        virtual ~ViewerCursorDisableCommand();
        
        static void init_info();
    };
}
