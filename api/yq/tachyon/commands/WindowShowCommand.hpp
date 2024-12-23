////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/WindowCommand.hpp>

namespace yq::tachyon {
    class Window;
    
    class WindowShowCommand : public WindowCommand {
        YQ_OBJECT_DECLARE(WindowShowCommand, WindowCommand)
    public:
    
        WindowShowCommand(Window*, const Param& p = {});
        virtual ~WindowShowCommand();
        
        static void init_info();
    };
}
