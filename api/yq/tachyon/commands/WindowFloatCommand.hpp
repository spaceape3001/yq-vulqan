////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/WindowCommand.hpp>

namespace yq::tachyon {
    class Viewer;
    
    class WindowFloatCommand : public WindowCommand {
        YQ_OBJECT_DECLARE(WindowFloatCommand, WindowCommand)
    public:
    
        struct Param : public WindowCommand::Param {
        };
    
        WindowFloatCommand(Viewer*, const Param& p = {});
        virtual ~WindowFloatCommand();
        
        static void init_info();
    };
}
