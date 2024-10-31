////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/ViewerCommand.hpp>

namespace yq::tachyon {
    class ViewerCloseCommand : public ViewerCommand {
        YQ_OBJECT_DECLARE(ViewerCloseCommand, ViewerCommand)
    public:
    
        struct Param : public ViewerCommand::Param {
        };
    
        ViewerCloseCommand(Viewer*, const Param& p = {});
        virtual ~ViewerCloseCommand();
    };
}
