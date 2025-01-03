////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/ViewerCommand.hpp>

namespace yq::tachyon {
    class Viewer;
    
    class ViewerFloatCommand : public ViewerCommand {
        YQ_OBJECT_DECLARE(ViewerFloatCommand, ViewerCommand)
    public:
    
        struct Param : public ViewerCommand::Param {
        };
    
        ViewerFloatCommand(Viewer*, const Param& p = {});
        virtual ~ViewerFloatCommand();
        
        static void init_info();
    };
}
