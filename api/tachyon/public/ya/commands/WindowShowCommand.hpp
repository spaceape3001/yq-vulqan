////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/WindowCommand.hpp>

namespace yq::tachyon {
    class Window;
    
    class WindowShowCommand : public WindowCommand {
        YQ_OBJECT_DECLARE(WindowShowCommand, WindowCommand)
    public:
    
        WindowShowCommand(Window*, const Param& p = {});
        WindowShowCommand(WindowID, const Param& p = {});
        virtual ~WindowShowCommand();
        
        static void init_info();
    };
}
