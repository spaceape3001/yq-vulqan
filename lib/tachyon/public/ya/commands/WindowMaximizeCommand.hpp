////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/WindowCommand.hpp>

namespace yq::tachyon {
    class Window;
    
    class WindowMaximizeCommand : public WindowCommand {
        YQ_OBJECT_DECLARE(WindowMaximizeCommand, WindowCommand)
    public:
    
        struct Param : public WindowCommand::Param {
        };
    
        WindowMaximizeCommand(Window*, const Param& p = {});
        WindowMaximizeCommand(WindowID, const Param& p = {});
        virtual ~WindowMaximizeCommand();
        
        static void init_info();
    };
}
