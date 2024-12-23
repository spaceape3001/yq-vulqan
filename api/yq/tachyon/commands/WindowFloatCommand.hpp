////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/WindowCommand.hpp>

namespace yq::tachyon {
    class Window;
    
    class WindowFloatCommand : public WindowCommand {
        YQ_OBJECT_DECLARE(WindowFloatCommand, WindowCommand)
    public:
    
        struct Param : public WindowCommand::Param {
        };
    
        WindowFloatCommand(Window*, const Param& p = {});
        virtual ~WindowFloatCommand();
        
        static void init_info();
    };
}
