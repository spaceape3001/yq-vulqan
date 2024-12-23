////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/WindowCommand.hpp>

namespace yq::tachyon {
    class Window;
    
    class WindowDestroyCommand : public WindowCommand {
        YQ_OBJECT_DECLARE(WindowDestroyCommand, WindowCommand)
    public:
    
        struct Param : public WindowCommand::Param {
        };
    
        WindowDestroyCommand(Window*, const Param& p = {});
        virtual ~WindowDestroyCommand();
        
        static void init_info();
    };
}
