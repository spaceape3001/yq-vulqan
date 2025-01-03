////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/WindowCommand.hpp>

namespace yq::tachyon {
    class Window;
    
    class WindowHideCommand : public WindowCommand {
        YQ_OBJECT_DECLARE(WindowHideCommand, WindowCommand)
    public:
    
        struct Param : public WindowCommand::Param {
        };
    
        WindowHideCommand(Window*, const Param& p = {});
        WindowHideCommand(WindowID, const Param& p = {});
        virtual ~WindowHideCommand();
        
        static void init_info();
    };
}
