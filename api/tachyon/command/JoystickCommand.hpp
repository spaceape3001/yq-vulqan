////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Command.hpp>
#include <tachyon/typedef/spatial.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class JoystickCommand : public Command {
        YQ_OBJECT_DECLARE(JoystickCommand, Command)
    public:
    
        static void init_info();

    protected:
        JoystickCommand(const Header&);
        JoystickCommand(const JoystickCommand&, const Header&);
        ~JoystickCommand();
        
    private:
        JoystickCommand(const JoystickCommand&) = delete;
        JoystickCommand(JoystickCommand&&) = delete;
        JoystickCommand& operator=(const JoystickCommand&) = delete;
        JoystickCommand& operator=(JoystickCommand&&) = delete;
    };
}
