////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/ViewerCommand.hpp>

namespace yq::tachyon {
    class ViewerFocusCommand : public ViewerCommand {
        YQ_OBJECT_DECLARE(ViewerFocusCommand, ViewerCommand)
    public:
    
        struct Param : public ViewerCommand::Param {
        };
    
        ViewerFocusCommand(Viewer*, const Param& p = {});
        virtual ~ViewerFocusCommand();
        
        static void init_info();
    };
}
