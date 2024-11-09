////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/WindowCommand.hpp>

namespace yq::tachyon {
    class Viewer;
    
    class WindowDestroyCommand : public WindowCommand {
        YQ_OBJECT_DECLARE(WindowDestroyCommand, WindowCommand)
    public:
    
        struct Param : public WindowCommand::Param {
        };
    
        WindowDestroyCommand(Viewer*, const Param& p = {});
        virtual ~WindowDestroyCommand();
        
        static void init_info();
    };
}
