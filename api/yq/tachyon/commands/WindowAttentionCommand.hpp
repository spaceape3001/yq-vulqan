////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/WindowCommand.hpp>

namespace yq::tachyon {
    class Window;
    
    class WindowAttentionCommand : public WindowCommand {
        YQ_OBJECT_DECLARE(WindowAttentionCommand, WindowCommand)
    public:
    
        struct Param : public WindowCommand::Param {
        };
    
        WindowAttentionCommand(Window*, const Param& p = {});
        virtual ~WindowAttentionCommand();
        
        static void init_info();
    };
}
