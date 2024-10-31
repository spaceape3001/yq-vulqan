////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/ViewerCommand.hpp>

namespace yq::tachyon {
    class ViewerHideCommand : public ViewerCommand {
        YQ_OBJECT_DECLARE(ViewerHideCommand, ViewerCommand)
    public:
    
        struct Param : public ViewerCommand::Param {
        };
    
        ViewerHideCommand(Viewer*, const Param& p = {});
        virtual ~ViewerHideCommand();
        
        static void init_info();
    };
}
