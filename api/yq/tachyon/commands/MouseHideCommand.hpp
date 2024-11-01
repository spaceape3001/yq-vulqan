////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/ViewerCommand.hpp>

namespace yq::tachyon {
    class MouseHideCommand : public ViewerCommand {
        YQ_OBJECT_DECLARE(MouseHideCommand, ViewerCommand)
    public:
    
        struct Param : public ViewerCommand::Param {
        };
    
        MouseHideCommand(Viewer*, const Param& p = {});
        virtual ~MouseHideCommand();
        
        static void init_info();
    };
}
