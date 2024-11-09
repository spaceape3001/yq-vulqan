////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/WindowCommand.hpp>

namespace yq::tachyon {
    class Viewer;
    
    class WindowShowCommand : public WindowCommand {
        YQ_OBJECT_DECLARE(WindowShowCommand, WindowCommand)
    public:
    
        struct Param : public WindowCommand::Param {
        };
    
        WindowShowCommand(Viewer*, const Param& p = {});
        virtual ~WindowShowCommand();
        
        static void init_info();
    };
}
