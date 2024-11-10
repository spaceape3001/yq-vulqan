////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/ViewerCommand.hpp>

namespace yq::tachyon {
    class ViewerCursorHideCommand : public ViewerCommand {
        YQ_OBJECT_DECLARE(ViewerCursorHideCommand, ViewerCommand)
    public:
    
        struct Param : public ViewerCommand::Param {
        };
    
        ViewerCursorHideCommand(Viewer*, const Param& p = {});
        virtual ~ViewerCursorHideCommand();
        
        static void init_info();
    };
}
