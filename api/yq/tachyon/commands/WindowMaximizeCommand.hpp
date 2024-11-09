////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/WindowCommand.hpp>

namespace yq::tachyon {
    class Viewer;
    
    class WindowMaximizeCommand : public WindowCommand {
        YQ_OBJECT_DECLARE(WindowMaximizeCommand, WindowCommand)
    public:
    
        struct Param : public WindowCommand::Param {
        };
    
        WindowMaximizeCommand(Viewer*, const Param& p = {});
        virtual ~WindowMaximizeCommand();
        
        static void init_info();
    };
}
