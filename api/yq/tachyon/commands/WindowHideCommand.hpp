////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/WindowCommand.hpp>

namespace yq::tachyon {
    class Window;
    
    class WindowHideCommand : public WindowCommand {
        YQ_OBJECT_DECLARE(WindowHideCommand, WindowCommand)
    public:
    
        struct Param : public WindowCommand::Param {
        };
    
        WindowHideCommand(Window*, const Param& p = {});
        virtual ~WindowHideCommand();
        
        static void init_info();
    };
}
