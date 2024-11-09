////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/WindowCommand.hpp>

namespace yq::tachyon {
    class Viewer;
    
    class WindowIconifyCommand : public WindowCommand {
        YQ_OBJECT_DECLARE(WindowIconifyCommand, WindowCommand)
    public:
    
        struct Param : public WindowCommand::Param {
        };
    
        WindowIconifyCommand(Viewer*, const Param& p = {});
        virtual ~WindowIconifyCommand();
        
        static void init_info();
    };
}