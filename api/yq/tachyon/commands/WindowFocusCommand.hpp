////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/WindowCommand.hpp>

namespace yq::tachyon {
    class Viewer;
    
    class WindowFocusCommand : public WindowCommand {
        YQ_OBJECT_DECLARE(WindowFocusCommand, WindowCommand)
    public:
    
        struct Param : public WindowCommand::Param {
        };
    
        WindowFocusCommand(Viewer*, const Param& p = {});
        virtual ~WindowFocusCommand();
        
        static void init_info();
    };
}
