////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/WindowCommand.hpp>

namespace yq::tachyon {
    class WindowCursorNormalCommand : public WindowCommand {
        YQ_OBJECT_DECLARE(WindowCursorNormalCommand, WindowCommand)
    public:
    
        struct Param : public WindowCommand::Param {
        };
    
        WindowCursorNormalCommand(Window*, const Param& p = {});
        WindowCursorNormalCommand(WindowID, const Param& p = {});
        virtual ~WindowCursorNormalCommand();
        
        static void init_info();
    };
}
