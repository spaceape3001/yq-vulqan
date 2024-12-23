////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/WindowCommand.hpp>

namespace yq::tachyon {
    class Window;
    
    class WindowFocusCommand : public WindowCommand {
        YQ_OBJECT_DECLARE(WindowFocusCommand, WindowCommand)
    public:
    
        struct Param : public WindowCommand::Param {
        };
    
        WindowFocusCommand(Window*, const Param& p = {});
        virtual ~WindowFocusCommand();
        
        static void init_info();
    };
}
