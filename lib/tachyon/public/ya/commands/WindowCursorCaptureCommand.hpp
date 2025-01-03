////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/WindowCommand.hpp>

namespace yq::tachyon {
    class WindowCursorCaptureCommand : public WindowCommand {
        YQ_OBJECT_DECLARE(WindowCursorCaptureCommand, WindowCommand)
    public:
    
        struct Param : public WindowCommand::Param {
        };
    
        WindowCursorCaptureCommand(Window*, const Param& p = {});
        WindowCursorCaptureCommand(WindowID, const Param& p = {});
        virtual ~WindowCursorCaptureCommand();
        
        static void init_info();
    };
}
