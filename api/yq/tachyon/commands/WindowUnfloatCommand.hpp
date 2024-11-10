////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/WindowCommand.hpp>

namespace yq::tachyon {
    class Viewer;
    
    class WindowUnfloatCommand : public WindowCommand {
        YQ_OBJECT_DECLARE(WindowUnfloatCommand, WindowCommand)
    public:
    
        struct Param : public WindowCommand::Param {
        };
    
        WindowUnfloatCommand(Viewer*, const Param& p = {});
        virtual ~WindowUnfloatCommand();
        
        static void init_info();
    };
}
