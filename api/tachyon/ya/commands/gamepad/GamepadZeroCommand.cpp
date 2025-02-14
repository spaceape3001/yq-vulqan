////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/gamepad/GamepadZeroCommand.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

namespace yq::tachyon {
    void GamepadZeroCommand::init_info()
    {
        auto w = writer<GamepadZeroCommand>();
        w.description("Gamepad Zeroion Command");
    }

    GamepadZeroCommand::GamepadZeroCommand(const Header&h) : GamepadCommand(h)
    {
    }
    
    GamepadZeroCommand::GamepadZeroCommand(const GamepadZeroCommand& cp, const Header&h) : GamepadCommand(cp, h)
    {
    }

    GamepadZeroCommand::~GamepadZeroCommand()
    {
    }

    PostCPtr    GamepadZeroCommand::clone(rebind_k, const Header&h) const
    {
        return new GamepadZeroCommand(*this, h);
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::GamepadZeroCommand)
