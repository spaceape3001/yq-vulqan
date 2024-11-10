////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/ViewerCommand.hpp>

namespace yq::tachyon {
    class Viewer;
    
    class ViewerUnfloatCommand : public ViewerCommand {
        YQ_OBJECT_DECLARE(ViewerUnfloatCommand, ViewerCommand)
    public:
    
        struct Param : public ViewerCommand::Param {
        };
    
        ViewerUnfloatCommand(Viewer*, const Param& p = {});
        virtual ~ViewerUnfloatCommand();
        
        static void init_info();
    };
}
