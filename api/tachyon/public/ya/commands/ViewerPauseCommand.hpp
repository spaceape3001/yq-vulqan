////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/ViewerCommand.hpp>

namespace yq::tachyon {
    class ViewerPauseCommand : public ViewerCommand {
        YQ_OBJECT_DECLARE(ViewerPauseCommand, ViewerCommand)
    public:
    
        struct Param : public ViewerCommand::Param {
        };
    
        ViewerPauseCommand(Viewer*, const Param& p = {});
        virtual ~ViewerPauseCommand();
        
        static void init_info();
    };
}
