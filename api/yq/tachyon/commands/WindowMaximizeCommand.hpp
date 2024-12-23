////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/WindowCommand.hpp>

namespace yq::tachyon {
    class Window;
    
    class WindowMaximizeCommand : public WindowCommand {
        YQ_OBJECT_DECLARE(WindowMaximizeCommand, WindowCommand)
    public:
    
        struct Param : public WindowCommand::Param {
        };
    
        WindowMaximizeCommand(Window*, const Param& p = {});
        virtual ~WindowMaximizeCommand();
        
        static void init_info();
    };
}
