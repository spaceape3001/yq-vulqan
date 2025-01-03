////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/ViewerCommand.hpp>

namespace yq::tachyon {
    class ViewerCursorNormalCommand : public ViewerCommand {
        YQ_OBJECT_DECLARE(ViewerCursorNormalCommand, ViewerCommand)
    public:
    
        struct Param : public ViewerCommand::Param {
        };
    
        ViewerCursorNormalCommand(Viewer*, const Param& p = {});
        virtual ~ViewerCursorNormalCommand();
        
        static void init_info();
    };
}
