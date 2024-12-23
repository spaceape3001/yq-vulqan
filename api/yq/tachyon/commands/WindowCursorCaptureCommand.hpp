////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/WindowCommand.hpp>

namespace yq::tachyon {
    class WindowCursorCaptureCommand : public WindowCommand {
        YQ_OBJECT_DECLARE(WindowCursorCaptureCommand, WindowCommand)
    public:
    
        struct Param : public WindowCommand::Param {
        };
    
        WindowCursorCaptureCommand(Window*, const Param& p = {});
        virtual ~WindowCursorCaptureCommand();
        
        static void init_info();
    };
}
