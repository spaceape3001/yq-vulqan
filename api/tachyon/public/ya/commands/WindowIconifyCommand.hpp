////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/WindowCommand.hpp>

namespace yq::tachyon {
    class Window;
    
    class WindowIconifyCommand : public WindowCommand {
        YQ_OBJECT_DECLARE(WindowIconifyCommand, WindowCommand)
    public:
    
        struct Param : public WindowCommand::Param {
        };
    
        WindowIconifyCommand(Window*, const Param& p = {});
        WindowIconifyCommand(WindowID, const Param& p = {});
        virtual ~WindowIconifyCommand();
        
        static void init_info();
    };
}
