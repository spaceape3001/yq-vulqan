////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/WindowCommand.hpp>

namespace yq::tachyon {
    class Viewer;
    
    class WindowRestoreCommand : public WindowCommand {
        YQ_OBJECT_DECLARE(WindowRestoreCommand, WindowCommand)
    public:
    
        struct Param : public WindowCommand::Param {
        };
    
        WindowRestoreCommand(Viewer*, const Param& p = {});
        virtual ~WindowRestoreCommand();
        
        static void init_info();
    };
}
