////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/GamepadCommand.hpp>

namespace yq::tachyon {
    class GamepadZeroCommand : public GamepadCommand {
        YQ_OBJECT_DECLARE(GamepadZeroCommand, GamepadCommand);
    public:
        static void init_meta();
    
        GamepadZeroCommand(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        GamepadZeroCommand(const GamepadZeroCommand&, const Header&);
        ~GamepadZeroCommand();
        
    private:
        GamepadZeroCommand(const GamepadZeroCommand&) = delete;
        GamepadZeroCommand(GamepadZeroCommand&&) = delete;
        GamepadZeroCommand& operator=(const GamepadZeroCommand&) = delete;
        GamepadZeroCommand& operator=(GamepadZeroCommand&&) = delete;
    };
}
