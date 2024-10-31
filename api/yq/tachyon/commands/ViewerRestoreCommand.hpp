////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/ViewerCommand.hpp>

namespace yq::tachyon {
    class ViewerRestoreCommand : public ViewerCommand {
        YQ_OBJECT_DECLARE(ViewerRestoreCommand, ViewerCommand)
    public:
    
        struct Param : public ViewerCommand::Param {
        };
    
        ViewerRestoreCommand(Viewer*, const Param& p = {});
        virtual ~ViewerRestoreCommand();
        
        static void init_info();
    };
}
