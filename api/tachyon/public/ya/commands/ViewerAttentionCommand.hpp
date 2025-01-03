////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/ViewerCommand.hpp>

namespace yq::tachyon {
    class ViewerAttentionCommand : public ViewerCommand {
        YQ_OBJECT_DECLARE(ViewerAttentionCommand, ViewerCommand)
    public:
    
        struct Param : public ViewerCommand::Param {
        };
    
        ViewerAttentionCommand(Viewer*, const Param& p = {});
        virtual ~ViewerAttentionCommand();
        
        static void init_info();
    };
}
