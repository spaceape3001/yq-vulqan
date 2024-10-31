////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/ViewerCommand.hpp>

namespace yq::tachyon {
    class ViewerResumeCommand : public ViewerCommand {
        YQ_OBJECT_DECLARE(ViewerResumeCommand, ViewerCommand)
    public:
    
        struct Param : public ViewerCommand::Param {
        };
    
        ViewerResumeCommand(Viewer*, const Param& p = {});
        virtual ~ViewerResumeCommand();
        
        static void init_info();
    };
}
