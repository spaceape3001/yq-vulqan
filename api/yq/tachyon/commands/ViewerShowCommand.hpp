////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/ViewerCommand.hpp>

namespace yq::tachyon {
    class ViewerShowCommand : public ViewerCommand {
        YQ_OBJECT_DECLARE(ViewerShowCommand, ViewerCommand)
    public:
    
        struct Param : public ViewerCommand::Param {
        };
    
        ViewerShowCommand(Viewer*, const Param& p = {});
        virtual ~ViewerShowCommand();
        
        static void init_info();
    };
}
