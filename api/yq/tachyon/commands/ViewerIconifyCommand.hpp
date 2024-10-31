////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/ViewerCommand.hpp>

namespace yq::tachyon {
    class ViewerIconifyCommand : public ViewerCommand {
        YQ_OBJECT_DECLARE(ViewerIconifyCommand, ViewerCommand)
    public:
    
        struct Param : public ViewerCommand::Param {
        };
    
        ViewerIconifyCommand(Viewer*, const Param& p = {});
        virtual ~ViewerIconifyCommand();
        
        static void init_info();
    };
}
