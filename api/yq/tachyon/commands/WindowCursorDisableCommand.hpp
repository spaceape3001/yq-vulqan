////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/WindowCommand.hpp>

namespace yq::tachyon {
    class WindowCursorDisableCommand : public WindowCommand {
        YQ_OBJECT_DECLARE(WindowCursorDisableCommand, WindowCommand)
    public:
    
        struct Param : public WindowCommand::Param {
        };
    
        WindowCursorDisableCommand(Window*, const Param& p = {});
        WindowCursorDisableCommand(WindowID, const Param& p = {});
        virtual ~WindowCursorDisableCommand();
        
        static void init_info();
    };
}
