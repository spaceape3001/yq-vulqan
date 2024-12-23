////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/WindowCommand.hpp>

namespace yq::tachyon {
    class Window;
    
    class WindowUnfloatCommand : public WindowCommand {
        YQ_OBJECT_DECLARE(WindowUnfloatCommand, WindowCommand)
    public:
    
        struct Param : public WindowCommand::Param {
        };
    
        WindowUnfloatCommand(Window*, const Param& p = {});
        WindowUnfloatCommand(WindowID, const Param& p = {});
        virtual ~WindowUnfloatCommand();
        
        static void init_info();
    };
}
