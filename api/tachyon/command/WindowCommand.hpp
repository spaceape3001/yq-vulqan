////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/msg/Command.hpp>

namespace yq::tachyon {
    class WindowCommand : public Command {
        YQ_OBJECT_DECLARE(WindowCommand, Command)
    public:
    
        static void init_info();

    protected:
    
        WindowCommand(const Header&);
        WindowCommand(const WindowCommand&, const Header&);
        virtual ~WindowCommand();
    
    private:    
        WindowCommand(const WindowCommand&) = delete;
        WindowCommand(WindowCommand&&) = delete;
        WindowCommand& operator=(const WindowCommand&) = delete;
        WindowCommand& operator=(WindowCommand&&) = delete;
    };
}
