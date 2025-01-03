////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/WindowCommand.hpp>

namespace yq::tachyon {
    class Window;
    
    class WindowDestroyCommand : public WindowCommand {
        YQ_OBJECT_DECLARE(WindowDestroyCommand, WindowCommand)
    public:
    
        struct Param : public WindowCommand::Param {
        };
    
        WindowDestroyCommand(Window*, const Param& p = {});
        WindowDestroyCommand(WindowID, const Param& p = {});
        virtual ~WindowDestroyCommand();
        
        static void init_info();
    };
}
