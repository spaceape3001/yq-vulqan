////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/ViewerCommand.hpp>

namespace yq::tachyon {
    class ViewerMaximizeCommand : public ViewerCommand {
        YQ_OBJECT_DECLARE(ViewerMaximizeCommand, ViewerCommand)
    public:
    
        struct Param : public ViewerCommand::Param {
        };
    
        ViewerMaximizeCommand(Viewer*, const Param& p = {});
        virtual ~ViewerMaximizeCommand();
        
        static void init_info();
    };
}
