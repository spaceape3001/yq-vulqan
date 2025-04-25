////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/msg/Command.hpp>
#include <tachyon/typedef/spatial.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class ThreadCommand : public Command {
        YQ_OBJECT_DECLARE(ThreadCommand, Command)
    public:
    
        static void init_info();

    protected:
        ThreadCommand(const Header&);
        ThreadCommand(const ThreadCommand&, const Header&);
        ~ThreadCommand();
        
    private:
        ThreadCommand(const ThreadCommand&) = delete;
        ThreadCommand(ThreadCommand&&) = delete;
        ThreadCommand& operator=(const ThreadCommand&) = delete;
        ThreadCommand& operator=(ThreadCommand&&) = delete;
    };
}
