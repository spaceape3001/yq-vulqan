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
    class GamepadCommand : public Command {
        YQ_OBJECT_DECLARE(GamepadCommand, Command)
    public:
    
        static void init_info();

    protected:
        GamepadCommand(const Header&);
        GamepadCommand(const GamepadCommand&, const Header&);
        ~GamepadCommand();
        
    private:
        GamepadCommand(const GamepadCommand&) = delete;
        GamepadCommand(GamepadCommand&&) = delete;
        GamepadCommand& operator=(const GamepadCommand&) = delete;
        GamepadCommand& operator=(GamepadCommand&&) = delete;
    };
}
